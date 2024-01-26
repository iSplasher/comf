set_project("comf")
set_version("0.0.0")

add_rules("mode.debug", "mode.release")
set_languages("cxxlatest")
set_defaultarchs("x64")
set_defaultmode("debug")

add_requires("vcpkg::efsw 1.3.1", {alias = "efsw"})
add_requires("vcpkg::cxxopts 3.1.1", {alias = "cxxopts"})
add_requires("vcpkg::entt 3.12.2", {alias = "entt"})


target("comf")
    set_kind("binary")
    add_files("src/*.cpp", "src/*.cppm", "src/**/*.cppm")
    add_packages("efsw")
    add_packages("cxxopts")
    add_packages("entt")
    -- enable automatic merging of all dependent static libraries
    set_policy("build.merge_archive", true)
target_end()
