// SPDX-License-Identifier: GPL-3.0

pragma solidity >=0.8.2 <0.9.0;
contract Array
{
    uint[4] public arr=[10,20,30,40];
    function setter(uint index,uint value) public 
    {
        arr[index]=value;
    }
    function length() public view  returns(uint)
    {
       return  arr.length;
    }
}