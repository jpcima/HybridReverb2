#!/bin/sh -e
set -x

locales="fr"

po_release() {
    local infile="$1"
    local outfile="$2"
    msginit -i "$infile" -o "$outfile" --stringtable-output --no-wrap --no-translator
}

mkdir -p I18n/release
for locale in $locales; do
    po_release I18n/"$locale"/HybridReverb2.po I18n/release/I18nResource_"$locale"
done
