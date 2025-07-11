#!/bin/bash

echo "Adding SPDX headers to all .c and .h files..."

find . -type f \( -name "*.c" -o -name "*.h" \) | while read -r file; do
    if grep -q "SPDX-License-Identifier" "$file"; then
        echo "✔️  $file already has SPDX tag, skipping"
    else
        echo "➕ Adding SPDX tag to $file"
        # Use a temp file to avoid issues with in-place editing
        {
            echo "// SPDX-License-Identifier: GPL-3.0-or-later"
            cat "$file"
        } > "$file.spdx"
        mv "$file.spdx" "$file"
    fi
done

echo "✅ Done."
