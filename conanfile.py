from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout
import os

class helloRecipe(ConanFile):
    name = "main"
    version = "1.0"
    package_type = "library"

    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True, "boost:shared":True}

    exports_sources = "CMakeLists.txt", "src/*", "include/*"

    def requirements(self):
        self.requires("boost/1.88.0")
        
    def layout(self):
        # 覆盖 build_folder，使其指向当前目录下的 `build` 文件夹
        self.folders.build = os.path.join(os.getcwd(), "build")
        self.folders.source = os.getcwd()  # 源码也在当前目录
        self.folders.generators = os.path.join(self.folders.build, "generators")

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        pass
        

    def package_info(self):
        self.cpp_info.libs = ["hello"]