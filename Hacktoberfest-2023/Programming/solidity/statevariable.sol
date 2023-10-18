// SPDX-License-Identifier: GPL-3.0

pragma solidity >=0.8.2 <0.9.0;
contract State
{
    uint age=10;  //state variables
    function getter() public view returns(uint)
    {
        return age;
    }
}
// 1-To change the default values of the state variables:-
//   * Using the contract constructor
//   *Initializing the variable at declaration
//   *Using the setter function
// 2-permanantly stored in contract storage
// 3-cost gas (expensive)
// 4-storage are not dynamicaaly allocated
// 5-Instance of the contract can not have other state variable besides those already declared