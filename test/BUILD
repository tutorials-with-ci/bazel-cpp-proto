cc_test(
    name = "unit_test",
    srcs = glob(["*.cc"]),
    copts = [
        "-std=c++11",
    ],
    deps = [
        "@gtest",
        "@gtest//:gtest_main",
        "//proto:address_book_cc",
    ],
)
