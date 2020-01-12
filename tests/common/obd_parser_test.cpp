#include <catch2/catch.hpp>


#include <common/obd_parser.h>

const std::string dataObd = 
"                               \n\
block                           \n\
    name grass                  \n\
    texture_top pack:grass      \n\
    texture_side pack:grasside  \n\
    texture_bottom pack:dirt    \n\
    mesh block                  \n\
    state solid                 \n\
end                             \n\
                                \n\
block                           \n\
    name dirt                   \n\
    texture_top pack:dirt       \n\
    mesh block                  \n\
    state solid                 \n\
end                             \n\
";  

TEST_CASE("OBD files can be read from correctly")
{
    auto data = getObdDataRaw(dataObd);

    SECTION("There are a correct number of parsed blocks") 
    {
        REQUIRE(data.size() == 2);

        REQUIRE(data[0].data.size() == 6);
        REQUIRE(data[1].data.size() == 4);
    }

    SECTION("It correctly has data") 
    {
        auto block = data[0];

        REQUIRE(block.data["name"] == "grass");
        REQUIRE(block.data["texture_top"] == "pack:grass");
        REQUIRE(block.data["texture_side"] == "pack:grasside");
        REQUIRE(block.data["texture_bottom"] == "pack:dirt");
        REQUIRE(block.data["mesh"] == "block");
        REQUIRE(block.data["state"] == "solid");


    }
}