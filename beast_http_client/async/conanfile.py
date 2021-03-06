
from conans import ConanFile, Meson

class HelloConan(ConanFile):
    name = "Hello"
    version = "0.1"
    settings = "os", "compiler", "build_type", "arch"
    #generators = "meson","gcc", "txt" 
    generators = "pkg_config"

    exports_sources = "./*"
    requires = (("boost/1.68.0@conan/stable"),("google-benchmark/1.4.1@mpusz/stable"))
    default_options = {"boost:shared": False}

    def build(self):
        meson = Meson(self)
        meson.configure()
        meson.build()

    def package(self):
        self.copy("*.h", dst="include", src="")
        self.copy("*.lib", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.dylib*", dst="lib", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["hello"]
