add_rules("mode.debug", "mode.release")

set_kind("binary")
set_plat("mingw")
set_arch("x86_64")
set_languages("c++17")

target("maze")
    add_includedirs("inc", "inc/block", "inc/block/empty")
    add_files("src/**.cpp")

    set_version("0.0.0")

    set_rundir("$(projectdir)")
    set_installdir("bin")

target("map_gen")
    add_includedirs("inc", "inc/block", "inc/block/empty")
    add_files("src/**.cpp|main.cpp")
    add_files("map_gen/**.cpp")

    set_rundir("map_gen")
