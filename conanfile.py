from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps
import os

class helloRecipe(ConanFile):
    name = "main"
    version = "1.0"
    package_type = "library"

    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {
        "shared": False,
        "fPIC": True,
        "boost/*:shared": True,
        "boost/*:without_dll": False
    }

    exports_sources = "CMakeLists.txt", "src/*", "include/*"

    def requirements(self):
        self.requires("boost/1.88.0")
        
    def layout(self):
        self.folders.build = os.path.join(os.getcwd(), "build")
        self.folders.source = os.getcwd()
        self.folders.generators = os.path.join(self.folders.build, "generators")
        
        # 确保目录存在
        os.makedirs(self.folders.generators, exist_ok=True)

    def generate(self):
        # 添加关键配置：Windows平台自动链接处理
        tc = CMakeToolchain(self)
        if self.settings.os == "Windows":
            tc.preprocessor_definitions["BOOST_ALL_NO_LIB"] = "1"
        tc.generate()
        
        # 生成find_package配置文件
        deps = CMakeDeps(self)
        deps.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def deploy(self):
        # 替换conan_create_deploy的新方法
        self.copy("*", dst="", src=self.package_folder)