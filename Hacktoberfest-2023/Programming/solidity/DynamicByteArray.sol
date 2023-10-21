// SPDX-License-Identifier: GPL-3.0

pragma solidity >=0.8.2 <0.9.0;
contract dynamicbytearray
{
    bytes public b1="abc";
    function pUshelement() public 
    {
        b1.push('d');
    }
    function getElement(uint i) public view returns(bytes1)
    {
      return b1[i];
    }
    function getlength() public view returns(uint)
    {
        return b1.length;
    }
}