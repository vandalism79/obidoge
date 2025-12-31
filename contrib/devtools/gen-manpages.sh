#!/bin/bash

# Determine top of source tree (works with or without .git)
if [ -z "${TOPDIR}" ]; then
  TOPDIR="$(git rev-parse --show-toplevel 2>/dev/null)" || true
  if [ -z "${TOPDIR}" ]; then
    TOPDIR="$(cd "$(dirname "$0")/../.." && pwd)"
  fi
fi

SRCDIR=${SRCDIR:-$TOPDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

OBIDOGED=${OBIDOGED:-$SRCDIR/obidoged}
OBIDOGECLI=${OBIDOGECLI:-$SRCDIR/obidoge-cli}
OBIDOGETX=${OBIDOGETX:-$SRCDIR/obidoge-tx}
OBIDOGEQT=${OBIDOGEQT:-$SRCDIR/qt/obidoge-qt}

[ ! -x "$OBIDOGED" ] && echo "$OBIDOGED not found or not executable." && exit 1
[ ! -x "$OBIDOGECLI" ] && echo "$OBIDOGECLI not found or not executable." && exit 1
[ ! -x "$OBIDOGETX" ] && echo "$OBIDOGETX not found or not executable." && exit 1
# Qt binary is optional (headless builders). If present, we'll generate a manpage for it.
HAS_QT=0
[ -x "$OBIDOGEQT" ] && HAS_QT=1

mkdir -p "$MANDIR"

# The autodetected version git tag can screw up manpage output a little bit
OBDVER=($("$OBIDOGECLI" --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
echo "[COPYRIGHT]" > footer.h2m
"$OBIDOGED" --version | sed -n '1!p' >> footer.h2m

# Build list of commands to document
CMDS=("$OBIDOGED" "$OBIDOGECLI" "$OBIDOGETX")
if [ "$HAS_QT" -eq 1 ]; then
  CMDS+=("$OBIDOGEQT")
fi

for cmd in "${CMDS[@]}"; do
  cmdname="${cmd##*/}"

  # bitcoin-qt / obidoge-qt often prints help to stderr; help2man discards stderr by default.
  # Also, qt apps commonly use -help rather than --help.
  EXTRA_OPTS=()
  if [ "$cmdname" = "obidoge-qt" ]; then
    EXTRA_OPTS+=(--no-discard-stderr --help-option=-help)
    # Ensure Qt doesn't need a display when generating docs.
    export QT_QPA_PLATFORM="${QT_QPA_PLATFORM:-offscreen}"
  fi

  help2man -N --version-string="${OBDVER[0]}" --include=footer.h2m     -o "${MANDIR}/${cmdname}.1" "${EXTRA_OPTS[@]}" "${cmd}"

  # Only run sed cleanup if file was created
  if [ -f "${MANDIR}/${cmdname}.1" ]; then
    sed -i "s/\\\-${OBDVER[1]}//g" "${MANDIR}/${cmdname}.1" || true
  fi
done

rm -f footer.h2m
