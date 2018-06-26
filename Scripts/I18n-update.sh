#!/bin/sh -e
set -x

locales="fr"

po_scan() {
    local dir="$1"
    local outfile="$2"
    find "$dir" \
         -iname '*.h' -o \
         -iname '*.c' -o \
         -iname '*.hpp' -o \
         -iname '*.cpp' -print0 | xargs -0 \
    xgettext --from-code=UTF-8 -k -kTRANS -kTRANS_UTF8 -kNEEDS_TRANS -C -c -s -o "$outfile"
}

po_update() {
    local infile="$1"t
    local outfile="$1"
    local locale="$2"
    if test -f "$outfile"; then
        msgmerge -s -U "$outfile" "$infile"
    else
        msginit -i "$infile" -o "$outfile" -l "$locale"
    fi
}

for locale in $locales; do
    mkdir -p I18n/"$locale"
    po_scan Source I18n/"$locale"/HybridReverb2.pot
    po_update I18n/"$locale"/HybridReverb2.po "$locale"
    rm -f I18n/"$locale"/HybridReverb2.pot
done
