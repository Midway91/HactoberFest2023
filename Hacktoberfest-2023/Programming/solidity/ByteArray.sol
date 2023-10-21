// SPDX-License-Identifier: GPL-3.0

pragma solidity >=0.8.2 <0.9.0;
//1byte=8bits
//1hexadecimal digit=4 bits
//Everything that will be stored in the byte array will be in the form of hxadecimal digit.

contract bytearray
{
    bytes3 public b3;
    bytes2 public b2;
    function setter() public {
        b3="abc";
        b2="ab";
    }
}

//Byte array can not be modified.
//padding of 0 is added at the end if the value(by which the array is initialized) does not occupy the entire space 