// SPDX-License-Identifier: GPL-3.0

pragma solidity >=0.8.2 <0.9.0;
contract con
{
    uint public count;
    constructor(uint new_count)
    {
        count=new_count;
    }
}

// 1-Executed only once.
// 2-you can create only one constructor and that is optional.
// 3-A default constructor is created by  the compiler if there is no explicitly defined constructor.