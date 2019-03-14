# CMake generated Testfile for 
# Source directory: D:/Science/avro_c++/_NCores
# Build directory: D:/Science/avro_c++/_NCores/cmake-build-debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(MallocAndBeyondTest "MallocAndBeyondTest")
add_test(SIMDBasisTest "SIMDBasisTest")
add_test(BandwidthTest "BandwidthTest")
add_test(ParallelBandwidthTest "ParallelBandwidthTest")
add_test(BasicTypeTest "BasicTypeTest")
add_test(BitsetTest "BitsetTest")
add_test(ClearMemory "ClearMemory")
add_test(DiskPerformanceTest "DiskPerformanceTest")
add_test(DiskAnsyncIOTest "DiskAnsyncIOTest")
add_test(BlockCacheTest "BlockCacheTest")
add_test(BlockManagerTest "BlockManagerTest")
add_test(BlockAppendTest "BlockAppendTest")
add_test(lz4CodecTest "lz4CodecTest")
add_test(RandomSeekTest "RandomSeekTest")
add_test(btreeTest "btreeTest")
add_test(TestTypes "TestTypes")
add_test(btreeTestBuild "btreeTestBuild")
add_test(btreeTestSearch "btreeTestSearch")
add_test(LSMBloomFilterTest "LSMBloomFilterTest")
subdirs("third-party/gtest-1.7.0/fused-src/gtest")
