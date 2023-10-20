// SPDX-License-Identifier: GPL-3.0

pragma solidity >=0.8.2 <0.9.0;
contract Dymanoc
{
    uint[] public arr;
    function pushElement(uint item) public{
        arr.push(item);
    }
    function Arrlength() public view returns(uint)
    {
        return arr.length;
    }
    function popElement() public
    {
        arr.pop();
    }
}