// SPDX-License-Identifier: GPL-3.0

pragma solidity >=0.8.2 <0.9.0;
contract local
{
    function getter() pure public returns(uint)
    {
        uint age=10;
        return age;
    }
}