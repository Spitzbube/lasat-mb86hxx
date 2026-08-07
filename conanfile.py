# Avoid "global" import of non-standard python module as the consumer will also have to install it.
# Use import in the respective method
import os

from conan import ConanFile
from conan.tools.files import copy, move_folder_contents
from conan.tools.scm import Git
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain

class LasatMb86hxx(ConanFile):
    name = "lasat-mb86hxx"
    version = "0.0.0"
    settings = "build_type", "os"
    generators = "VirtualBuildEnv"

    def configure(self):
        self.output.info("configure(self)")
        
    def requirement(self):
        self.output.info("requirement (self)")

    def export(self):
        self.output.info("export(self)")
        
    def source(self):
        self.output.info(f"source(self): self.folders.root = {self.folders.root}")
        self.output.info(f"self.source_folder = {self.source_folder}")
        copy(self, "*", os.path.join("/workspaces/", self.name), self.source_folder)

    def layout(self):
        self.output.info(f"layout(self): self.folders.root = {self.folders.root}")
        self.folders.source = "."
        self.folders.build = "build"
        self.folders.generators = "build"

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()
        deps = CMakeDeps(self)
        deps.generate()

    def build(self):
        self.output.info(f"Source folder set to {self.source_folder}")
        self.output.info(f"Build folder set to {self.build_folder}")

        cmake = CMake(self)
        cmake.configure()
        cmake.build()

#    def package(self):
    

