// SPDX-License-Identifier: GPL-3.0

pragma solidity >=0.8.2 <0.9.0;
contract ViewPure
{
    uint public age=10;
    function getter() public view  returns(uint)
    {
        return age;
    }
    function get() public 
    {
        
    }
    function getterd() public pure returns(uint)
    {
            uint roll=30;
            return roll;
    }
}

//View
//   *Read is Allowed but modification is not allowed(write) state variables
//Pure
//  *Both read and modification is not allowed in state variables(write)