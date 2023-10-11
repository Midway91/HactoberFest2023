// SPDX-License-Identifier: GPL-3.0

pragma solidity >=0.8.2 <0.9.0;
contract Array
{
    function check(int a) public pure returns(string memory)
    {
        string memory value;
        if(a>0)
        {
            value="a is greater than 0";
        }
        else if(a==0)
        {
            value="a is equal to zero";
        }
        else 
        {
            value="less than zero";
        }
        return value;
    }
}