// SPDX-License-Identifier: GPL-3.0

pragma solidity >=0.8.2 <0.9.0;

contract BooleanWithAccessControl {
    bool public value = true;
    address public owner;

    event ValueChanged(bool newValue, address indexed modifier);

    constructor() {
        owner = msg.sender;
    }

    modifier onlyOwner() {
        require(msg.sender == owner, "Only the owner can modify the value");
        _;
    }

    function setValue(bool newValue) public onlyOwner {
        value = newValue;
        emit ValueChanged(value, msg.sender);
    }

    function check(int a) public view returns (bool) {
        if (a > 100) {
            return value;
        } else {
            // Additional conditional logic
            // You can add more conditions here
            return false;
        }
    }
}
