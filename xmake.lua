add_rules("mode.debug", "mode.release")

target("maze")
    set_kind("binary")
    set_plat("mingw")
    set_arch("x86_64")
    set_languages("c++17")

    add_includedirs("inc", "inc/block", "inc/block/empty")
    add_files("src/**.cpp")

    set_version("0.0.0")
    set_installdir("bin")
