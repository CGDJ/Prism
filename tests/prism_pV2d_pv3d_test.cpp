#include "pch.h"// pch.h should #include "gtest/gtest.h" 
#include "Prism_vectors.h"

TEST(prism_vectors_pv2d, init_test) {
	pV2d v;
  EXPECT_FLOAT_EQ(v.x, 0);
  EXPECT_FLOAT_EQ(v.y, 0);
  pV2d v2(12, 8);
  EXPECT_FLOAT_EQ(v2.x, 12);
  EXPECT_FLOAT_EQ(v2.y, 8);
  pV2d v3(v2);
  EXPECT_FLOAT_EQ(v3.x, 12);
  EXPECT_FLOAT_EQ(v3.y, 8);
}
TEST(prism_vectors_pv2d, copy_to_test) {
	pV2d v(12, 8);
	float f[2];
	v.copyTo(f);
	EXPECT_FLOAT_EQ(f[0], 12);
	EXPECT_FLOAT_EQ(f[1], 8);
}
TEST(prism_vectors_pv2d, magnitude_test) {
	pV2d v(10,0);
	EXPECT_FLOAT_EQ(v.magnitude(), 10);
	pV2d v2(0, 5);
	EXPECT_FLOAT_EQ(v2.magnitude(), 5);
}
TEST(prism_vectors_pv2d, distance_to_test) {
	pV2d v(10, 0);
	pV2d v2(5, 0);
	EXPECT_FLOAT_EQ(v2.distanceTo(v), 5);
}
TEST(prism_vectors_pv2d, crossProduct_test) {
	pV2d v(10, 1);
	pV2d v2(5, 1);
	EXPECT_FLOAT_EQ(v.crossProduct(v2), 5);
}
TEST(prism_vectors_pv2d, normalize_test) {
	pV2d v(0, 0);
	EXPECT_FLOAT_EQ(v.normalize().x,0 );
	EXPECT_FLOAT_EQ(v.normalize().y, 0);
	pV2d v2(20, 550);
	EXPECT_FLOAT_EQ(v2.normalize().x, 0.036339618f);
	EXPECT_FLOAT_EQ(v2.normalize().y, 0.99933946f);
}
TEST(prism_vectors_pv2d, isNullVector_test) {
	pV2d v;
	pV2d v2(5, 1);
	EXPECT_TRUE(v.isNullVector());
	EXPECT_FALSE(v2.isNullVector());
}
TEST(prism_vectors_pv2d, Equals_operator_test) {
	pV2d v(10, 1);
	pV2d v2(5, 7);
	v2 = v;
	EXPECT_FLOAT_EQ(v2.x, 10);
	EXPECT_FLOAT_EQ(v2.y, 1);
}
TEST(prism_vectors_pv2d, plus_operator_test) {
	pV2d v(10, 1);
	pV2d v2(5, 7);
	v2 = v + v2;
	EXPECT_FLOAT_EQ(v2.x, 15);
	EXPECT_FLOAT_EQ(v2.y, 8);
}
TEST(prism_vectors_pv2d, subtract_operator_test) {
	pV2d v(10, 1);
	pV2d v2(5, 7);
	v2 = v - v2;
	EXPECT_FLOAT_EQ(v2.x, 5);
	EXPECT_FLOAT_EQ(v2.y, -6);
}
TEST(prism_vectors_pv2d, multiply_operator_test) {
	pV2d v(10, 1);
	pV2d v2(5, 2);
	v2 = v * v2;
	EXPECT_FLOAT_EQ(v2.x, 50);
	EXPECT_FLOAT_EQ(v2.y, 2);
}
TEST(prism_vectors_pv2d, divide_operator_test) {
	pV2d v(10, 20);
	pV2d v2(2, 2);
	v2 = v / v2;
	EXPECT_FLOAT_EQ(v2.x, 5);
	EXPECT_FLOAT_EQ(v2.y, 10);
}
TEST(prism_vectors_pv2d, chain_operator_test) {
	pV2d v(4, 4);
	pV2d v2(1, 1);
	v2 = (((v + v2) * v)-v)/v ;
	EXPECT_FLOAT_EQ(v2.x, 4);
	EXPECT_FLOAT_EQ(v2.y, 4);
}
TEST(prism_vectors_pv2d, increment_operator_test) {
	pV2d v(4, 5);
	v++;
	EXPECT_FLOAT_EQ(v.x, 5);
	EXPECT_FLOAT_EQ(v.y, 6);
	++v;
	EXPECT_FLOAT_EQ(v.x, 6);
	EXPECT_FLOAT_EQ(v.y, 7);
}
TEST(prism_vectors_pv2d, decrement_operator_test) {
	pV2d v(4, 5);
	v--;
	EXPECT_FLOAT_EQ(v.x, 3);
	EXPECT_FLOAT_EQ(v.y, 4);
	--v;
	EXPECT_FLOAT_EQ(v.x, 2);
	EXPECT_FLOAT_EQ(v.y, 3);
}
TEST(prism_vectors_pv2d, set_test) {
	pV2d v(4, 5);
	EXPECT_FLOAT_EQ(v.x, 4);
	EXPECT_FLOAT_EQ(v.y, 5);
	v.set(8, 7);
	EXPECT_FLOAT_EQ(v.x, 8);
	EXPECT_FLOAT_EQ(v.y, 7);
}
/// pV3d tests ////////////////////////////////////////////////

TEST(prism_vectors_pV3d, init_test) {
	pV3d v;
	EXPECT_FLOAT_EQ(v.x, 0);
	EXPECT_FLOAT_EQ(v.y, 0);
	EXPECT_FLOAT_EQ(v.z, 0);
	pV3d v2(12, 8,1);
	EXPECT_FLOAT_EQ(v2.x, 12);
	EXPECT_FLOAT_EQ(v2.y, 8);
	EXPECT_FLOAT_EQ(v2.z, 1);
	pV3d v3(v2);
	EXPECT_FLOAT_EQ(v3.x, 12);
	EXPECT_FLOAT_EQ(v3.y, 8);
	EXPECT_FLOAT_EQ(v3.z, 1);
	pV2d twoD(5,6);
	pV3d v4(twoD);
	EXPECT_FLOAT_EQ(v4.x, 5);
	EXPECT_FLOAT_EQ(v4.y, 6);
	EXPECT_FLOAT_EQ(v4.z, 0);
	pV3d v5(twoD,3);
	EXPECT_FLOAT_EQ(v5.x, 5);
	EXPECT_FLOAT_EQ(v5.y, 6);
	EXPECT_FLOAT_EQ(v5.z, 3);
}
TEST(prism_vectors_pV3d, copy_to_test) {
	pV3d v(12, 8,5);
	float f[3];
	v.copyTo(f);
	EXPECT_FLOAT_EQ(f[0], 12);
	EXPECT_FLOAT_EQ(f[1], 8);
	EXPECT_FLOAT_EQ(f[2], 5);
}
TEST(prism_vectors_pV3d, magnitude_test) {
	pV3d v(10, 0,0);
	EXPECT_FLOAT_EQ(v.magnitude(), 10);
	pV3d v2(0, 5,0);
	EXPECT_FLOAT_EQ(v2.magnitude(), 5);
	pV3d v3(0, 0, 8);
	EXPECT_FLOAT_EQ(v3.magnitude(), 8);
}
TEST(prism_vectors_pV3d, distance_to_test) {
	pV3d v(10, 0,0);
	pV3d v2(5, 0,0);
	EXPECT_FLOAT_EQ(v2.distanceTo(v), 5);
}
TEST(prism_vectors_pV3d, crossProduct_test) {
	pV3d v(10, 1,5);
	pV3d v2(5, 1,5);
	EXPECT_FLOAT_EQ(v.crossProduct(v2).x, 0);
	EXPECT_FLOAT_EQ(v.crossProduct(v2).y, -25);
	EXPECT_FLOAT_EQ(v.crossProduct(v2).z, 5);
}
TEST(prism_vectors_pV3d, normalize_test) {
	pV3d v(0, 0,0);
	EXPECT_FLOAT_EQ(v.normalize().x, 0);
	EXPECT_FLOAT_EQ(v.normalize().y, 0);
	EXPECT_FLOAT_EQ(v.normalize().z, 0);
	pV3d v2(20, 550,0);
	EXPECT_FLOAT_EQ(v2.normalize().x, 0.036339618f);
	EXPECT_FLOAT_EQ(v2.normalize().y, 0.99933946f);
	EXPECT_FLOAT_EQ(v2.normalize().z,0);
}
TEST(prism_vectors_pV3d, isNullVector_test) {
	pV3d v;
	pV3d v2(5, 1);
	EXPECT_TRUE(v.isNullVector());
	EXPECT_FALSE(v2.isNullVector());
}
TEST(prism_vectors_pV3d, Equals_operator_test) {
	pV3d v(10, 1,2);
	pV3d v2(5, 7,5);
	v2 = v;
	EXPECT_FLOAT_EQ(v2.x, 10);
	EXPECT_FLOAT_EQ(v2.y, 1);
	EXPECT_FLOAT_EQ(v2.z, 2);
}
TEST(prism_vectors_pV3d, plus_operator_test) {
	pV3d v(10, 1,5);
	pV3d v2(5, 7,5);
	v2 = v + v2;
	EXPECT_FLOAT_EQ(v2.x, 15);
	EXPECT_FLOAT_EQ(v2.y, 8);
	EXPECT_FLOAT_EQ(v2.z, 10);
}
TEST(prism_vectors_pV3d, subtract_operator_test) {
	pV3d v(10, 1,1);
	pV3d v2(5, 7,3);
	v2 = v - v2;
	EXPECT_FLOAT_EQ(v2.x, 5);
	EXPECT_FLOAT_EQ(v2.y, -6);
	EXPECT_FLOAT_EQ(v2.z, -2);
}
TEST(prism_vectors_pV3d, multiply_operator_test) {
	pV3d v(10, 1,5);
	pV3d v2(5, 2,1);
	v2 = v * v2;
	EXPECT_FLOAT_EQ(v2.x, 50);
	EXPECT_FLOAT_EQ(v2.y, 2);
	EXPECT_FLOAT_EQ(v2.z, 5);
}
TEST(prism_vectors_pV3d, divide_operator_test) {
	pV3d v(10, 20,18);
	pV3d v2(2, 2,2);
	v2 = v / v2;
	EXPECT_FLOAT_EQ(v2.x, 5);
	EXPECT_FLOAT_EQ(v2.y, 10);
	EXPECT_FLOAT_EQ(v2.z, 9);
}
TEST(prism_vectors_pV3d, chain_operator_test) {
	pV3d v(4, 4,1);
	pV3d v2(1, 1,1);
	v2 = (((v + v2) * v) - v) / v;
	EXPECT_FLOAT_EQ(v2.x, 4);
	EXPECT_FLOAT_EQ(v2.y, 4);
	EXPECT_FLOAT_EQ(v2.z, 1);
}
TEST(prism_vectors_pV3d, increment_operator_test) {
	pV3d v(4, 5,2);
	v++;
	EXPECT_FLOAT_EQ(v.x, 5);
	EXPECT_FLOAT_EQ(v.y, 6);
	EXPECT_FLOAT_EQ(v.z, 3);
	++v;
	EXPECT_FLOAT_EQ(v.x, 6);
	EXPECT_FLOAT_EQ(v.y, 7);
	EXPECT_FLOAT_EQ(v.z, 4);
}
TEST(prism_vectors_pV3d, decrement_operator_test) {
	pV3d v(4, 5,5);
	v--;
	EXPECT_FLOAT_EQ(v.x, 3);
	EXPECT_FLOAT_EQ(v.y, 4);
	EXPECT_FLOAT_EQ(v.z, 4);
	--v;
	EXPECT_FLOAT_EQ(v.x, 2);
	EXPECT_FLOAT_EQ(v.y, 3);
	EXPECT_FLOAT_EQ(v.z, 3);
}
TEST(prism_vectors_pv3d, set_test) {
	pV3d v(4, 5,12);
	EXPECT_FLOAT_EQ(v.x, 4);
	EXPECT_FLOAT_EQ(v.y, 5);
	EXPECT_FLOAT_EQ(v.z, 12);
	v.set(8, 7);
	EXPECT_FLOAT_EQ(v.x, 8);
	EXPECT_FLOAT_EQ(v.y, 7);
	EXPECT_FLOAT_EQ(v.z, 12);
	v.set(1,1,1);
	EXPECT_FLOAT_EQ(v.x, 1);
	EXPECT_FLOAT_EQ(v.y, 1);
	EXPECT_FLOAT_EQ(v.z, 1);
}