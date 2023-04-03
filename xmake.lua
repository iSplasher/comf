set_project("core")
set_version("0.0.0")

add_rules("mode.debug", "mode.release")
set_languages("cxxlatest")
set_defaultarchs("x64")
set_defaultmode("debug")

add_requires("vcpkg::efsw", {alias = "efsw"})


target("core")
    set_kind("binary")
    add_files("src/*.cpp", "src/**/*.cppm")
    add_packages("efsw")
target_end()