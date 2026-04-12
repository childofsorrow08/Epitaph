local assets_dir = "assets/fonts/"
local output_c = "build/generated/src/assets.c"
local output_h = "build/generated/include/epitaph_assets.h"

local function map_variable_name(filename)
    local name = filename:gsub("%.ttf$", "")
    
    name = name:gsub("([%l%d])(%u)", "%1_%2")
    
    name = name:gsub("%-", "_")
    
    name = name:lower()
    
    name = name:gsub("__+", "_")
    
    return name
end

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
    local cmd = is_windows and ("dir /b \"" .. dir:gsub("/", "\\") .. "*.ttf\"") or ("ls -1 " .. dir)
    
    local p = io.popen(cmd)
    if not p then return files end
    for file in p:lines() do
        if file:match("%.ttf$") then
            table.insert(files, { 
                full_path = dir .. file, 
                var_name = map_variable_name(file) 
            })
        end
    end
    p:close()
    return files
end

ensure_dir(output_c)
ensure_dir(output_h)

local ttf_files = get_ttf_files(assets_dir)
local file_c = io.open(output_c, "w")
local file_h = io.open(output_h, "w")

file_h:write("#ifndef EPITAPH_ASSETS_H\n#define EPITAPH_ASSETS_H\n\n#include <stddef.h>\n\n")
file_c:write("#include \"epitaph_assets.h\"\n\n")

for _, asset in ipairs(ttf_files) do
    local f = io.open(asset.full_path, "rb")
    if f then
        local data = f:read("*all")
        f:close()
        local size = #data
        
        file_h:write(string.format("extern const unsigned char %s[];\n", asset.var_name))
        file_h:write(string.format("extern const size_t %s_len;\n\n", asset.var_name))

        file_c:write(string.format("const unsigned char %s[] = {", asset.var_name))
        for i = 1, size do
            if (i - 1) % 12 == 0 then file_c:write("\n    ") end
            file_c:write(string.format("0x%02X%s", string.byte(data, i), i == size and "" or ", "))
        end
        file_c:write("\n};\n")
        file_c:write(string.format("const size_t %s_len = %d;\n\n", asset.var_name, size))
        print("Generated: " .. asset.var_name)
    end
end

file_h:write("#endif\n")
file_c:close()
file_h:close()