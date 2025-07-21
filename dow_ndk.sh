# 检查普通文件是否存在
if [ -f "$PWD/android_ndk" ]; then
    echo "ndk已安装"
else
    echo "ndk未安装"
    wget -O android.zip https://googledownloads.cn/android/repository/android-ndk-r27d-linux.zip
    unzip android.zip 
    mv android-ndk-r27d /opt/android_ndk
fi

# 检查任意类型的文件/目录是否存在
#if [ -e "/path/to/file" ]; then
#    echo "文件或目录存在"
#fi
