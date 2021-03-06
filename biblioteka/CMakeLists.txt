cmake_minimum_required(VERSION 3.4)
project(Biblioteka)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/model/Client.cpp
    src/model/Address.cpp
    src/model/Vehicle.cpp
    src/model/Rent.cpp
        src/Vehicles/MotorVehicle.cpp
        src/Vehicles/Bicycle.cpp
        src/Vehicles/Car.cpp
        src/Vehicles/Mope.cpp
        src/Repositories/RentsRepository.cpp
        src/Repositories/VehicleRepository.cpp
    src/model/ClientType.cpp
        src/ClientTypes/StandardClientType.cpp
        src/ClientTypes/PremiumClientType.cpp
        src/ClientTypes/VipClientType.cpp
        src/Repositories/ClientRepository.cpp
        src/Managers/RentsManager.cpp
        src/Exceptions/ClientException.cpp
        src/Exceptions/RentsManagerException.cpp
        src/Exceptions/VehicleException.cpp
        src/Managers/ClientManager.cpp
        src/Managers/VehicleManager.cpp
        src/Exceptions/ClientManagerException.cpp
        src/Exceptions/VehicleManagerException.cpp)

add_library(Biblioteka ${SOURCE_FILES})

#dolacz katalog z plikami naglowkowymi include z projektu biblioteka do sciezek
target_include_directories(Biblioteka PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

#Sekcja testów
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

set(SOURCE_TEST_FILES
        test/master.cpp
        test/RentTest.cpp
        test/VehicleTest.cpp
        test/ClientTest.cpp
        test/VehicleRepositoryTest.cpp
        test/VehicleManagerTest.cpp
        test/ClientManagerTest.cpp
        test/RentsManagerTest.cpp
        test/RentsRepositoryTest.cpp
        test/ClientRepositoryTest.cpp)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

add_executable (Test ${SOURCE_TEST_FILES})

target_link_libraries (Test
        Biblioteka
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

enable_testing()
add_test(TestBiblioteki Test)
