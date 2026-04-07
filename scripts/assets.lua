-- Run this script from the project's root directory
-- Linux: lua scripts/assets.lua 
-- Windows: lua scripts\assets.lua

local assets_dir = "assets/fonts/"
local output_c = "build/generated/src/assets.c"
local output_h = "build/generated/include/epitaph_assets.h"
local prefix = "ea_"

-- Function to ensure directories exist (mkdir -p)
local function ensure_dir(file_path)
    local sep = package.config:sub(1,1)
    local dir = file_path:match("(.*[/\\])")
    if dir then
        if sep == "\\" then
            os.execute("if not exist \"" .. dir .. "\" mkdir \"" .. dir .. "\"")
        else
            os.execute("mkdir -p " .. dir)
        end
    end
end

local function get_ttf_files(dir)
    local files = {}
    local is_windows = package.config:sub(1,1) == "\\"
    -- Use raw ls/dir and filter within Lua for better reliability on Gentoo/Linux
    local cmd = is_windows and ("dir /b \"" .. dir:gsub("/", "\\") .. "*.ttf\"") or ("ls -1 " .. dir)
    
    local p = io.popen(cmd)
    if not p then return files end

    for file in p:lines() do
        -- Filter .ttf files and clean names
        if file:match("%.ttf$") then
            local name = file:gsub("%.ttf$", "")
            local var_name = prefix .. name:gsub("[^%w]", "_")
            
            table.insert(files, { 
                full_path = dir .. file, 
                var_name = var_name 
            })
        end
    end
    p:close()
    return files
end

-- Create build directories if they don't exist
ensure_dir(output_c)
ensure_dir(output_h)

local ttf_files = get_ttf_files(assets_dir)

if #ttf_files == 0 then
    print("Error: No .ttf files found in " .. assets_dir)
    return
end

local file_c = io.open(output_c, "w")
local file_h = io.open(output_h, "w")

-- Header guards and includes
file_h:write("#ifndef EPITAPH_ASSETS_H\n#define EPITAPH_ASSETS_H\n\n#include <stddef.h>\n\n")
-- Adjusted include path to point to the generated header
file_c:write("#include \"../include/epitaph_assets.h\"\n\n")

for _, asset in ipairs(ttf_files) do
    local f = io.open(asset.full_path, "rb")
    if f then
        local data = f:read("*all")
        f:close()

        local size = #data
        
        -- Write externs to .h
        file_h:write(string.format("extern const unsigned char %s[];\n", asset.var_name))
        file_h:write(string.format("extern const size_t %s_size;\n\n", asset.var_name))

        -- Write byte arrays to .c
        file_c:write(string.format("const unsigned char %s[] = {", asset.var_name))
        for i = 1, size do
            if (i - 1) % 12 == 0 then file_c:write("\n    ") end
            file_c:write(string.format("0x%02X%s", string.byte(data, i), i == size and "" or ", "))
        end
        file_c:write("\n};\n")
        file_c:write(string.format("const size_t %s_size = %d;\n\n", asset.var_name, size))
        
        print("Processed: " .. asset.full_path)
    else
        print("Failed to open: " .. asset.full_path)
    end
end

file_h:write("#endif // EPITAPH_ASSETS_H\n")

file_c:close()
file_h:close()

print("\nDone. Files generated in build/generated/")