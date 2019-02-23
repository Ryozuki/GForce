/* 
 * (c) Ryozuki See LICENSE.txt in the root of the distribution for more information.
 * If you are missing that file, acquire a complete release at https://github.com/Ryozuki/GForce
 */

#include <gtest/gtest.h>
#include <GForce/VMath.hpp>
#include <GForce/Math.hpp>

TEST(Vectors, Constructor)
{
    gf::Vector2D vec(2, 4);
    EXPECT_DOUBLE_EQ(vec.x, 2);
    EXPECT_DOUBLE_EQ(vec.w, 2);
    EXPECT_DOUBLE_EQ(vec.y, 4);
    EXPECT_DOUBLE_EQ(vec.h, 4);

    gf::Vector3D vec3(2, 7.5, 3.4);
    EXPECT_DOUBLE_EQ(vec3.x, 2);
    EXPECT_DOUBLE_EQ(vec3.y, 7.5);
    EXPECT_DOUBLE_EQ(vec3.z, 3.4);
    EXPECT_DOUBLE_EQ(vec3.width, 3.4);
    EXPECT_DOUBLE_EQ(vec3.height, 3.4);
    EXPECT_DOUBLE_EQ(vec3.depth, 3.4);
}

TEST(Vectors, Addition)
{
    gf::Vector2D vec = gf::Vector2D(2, 4) + gf::Vector2D(4, 2);
    EXPECT_DOUBLE_EQ(vec.x, 6);
    EXPECT_DOUBLE_EQ(vec.w, 6);
    EXPECT_DOUBLE_EQ(vec.y, 6);
    EXPECT_DOUBLE_EQ(vec.h, 6);

    gf::Vector3D vec3 = gf::Vector3D(5, 6, 1) + gf::Vector3D(2, 3, 5);
    EXPECT_DOUBLE_EQ(vec3.x, 7);
    EXPECT_DOUBLE_EQ(vec3.y, 9);
    EXPECT_DOUBLE_EQ(vec3.z, 6);
}

TEST(Vectors, Substraction)
{
    gf::Vector2D vec = gf::Vector2D(2, 4) - gf::Vector2D(4, 2);
    EXPECT_DOUBLE_EQ(vec.x, -2);
    EXPECT_DOUBLE_EQ(vec.w, -2);
    EXPECT_DOUBLE_EQ(vec.y, 2);
    EXPECT_DOUBLE_EQ(vec.h, 2);

    gf::Vector3D vec3 = gf::Vector3D(5, 6, 1) + gf::Vector3D(2, 3, 5);
    EXPECT_DOUBLE_EQ(vec3.x, 3);
    EXPECT_DOUBLE_EQ(vec3.y, 3);
    EXPECT_DOUBLE_EQ(vec3.z, -4);
}

TEST(Vectors, Equal)
{
    gf::Vector2D vec(3, 4);
    gf::Vector2D vec2(3, 4);
    gf::Vector2D vec3(4, 4);
    EXPECT_EQ(vec, vec2);
    EXPECT_NE(vec2, vec3);

    gf::Vector3D vector3D1(3, 3, 2);
    gf::Vector3D vector3D2(5, 3, 2);
    gf::Vector3D vector3D3(3, 3, 2);
    EXPECT_EQ(vector3D1, vector3D3);
    EXPECT_NE(vector3D1, vector3D2);
    EXPECT_NE(vector3D3, vector3D2);
}

TEST(Vectors, Length)
{
    gf::Vector2D vec(3, 4);
    gf::Vector2D vec2(9, 3);
    gf::Vector2D vec3(4, 7);
    gf::Vector2D vec4(6, 6);
    EXPECT_EQ(vec.length(), 5);
    EXPECT_DOUBLE_EQ(vec2.length(), 9.4868329805051381);
    EXPECT_FLOAT_EQ(vec3.length(), 8.06226);
    EXPECT_FLOAT_EQ(vec4.length(), 8.48528);

    gf::Vector3D vector3D1(2, 6, 7);
    EXPECT_DOUBLE_EQ(vector3D1.length(), 9.4339811320566032);
}

TEST(Vectors, AngleBetweenTwoVectors)
{
    gf::Vector2D vec(3, 4);
    gf::Vector2D vec2(4, 3);
    EXPECT_DOUBLE_EQ(vec.angleWith(vec2), 0.96);

    gf::Vector2D vec3(7, 1);
    gf::Vector2D vec4(5, 5);
    EXPECT_DOUBLE_EQ(vec3.angleWith(vec4), 0.8);

    gf::Vector3D vector3D1(4, 5, 2);
    gf::Vector3D vector3D2(5, 2, 5);
    EXPECT_DOUBLE_EQ(vector3D1.angleWith(vector3D2), 0.81144082593357936);
}

TEST(Vectors, Angle)
{
    gf::Vector2D vec(3, 4);
    EXPECT_DOUBLE_EQ(vec.angle(), 0.78539816339744828);
    EXPECT_DOUBLE_EQ(gf::Math::toDegrees(vec.angle()) , 45);
}

TEST(Vectors, Direction)
{
    gf::Vector2D vec(3, 4);
    EXPECT_EQ(vec.direction(), gf::Vector2D(0.6, 0.8));
}

TEST(Vectors, CalculateNormal)
{
    gf::Vector2D vec(3, 4);
    EXPECT_EQ(vec.normal(), gf::Vector2D(-4, 3));
}


