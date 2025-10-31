script_folder="/data/data/com.termux/files/home/box/build/generators"
echo "echo Restoring environment" > "$script_folder/deactivate_conanrunenv-release-armv7.sh"
for v in 
do
    is_defined="true"
    value=$(printenv $v) || is_defined="" || true
    if [ -n "$value" ] || [ -n "$is_defined" ]
    then
        echo export "$v='$value'" >> "$script_folder/deactivate_conanrunenv-release-armv7.sh"
    else
        echo unset $v >> "$script_folder/deactivate_conanrunenv-release-armv7.sh"
    fi
done

