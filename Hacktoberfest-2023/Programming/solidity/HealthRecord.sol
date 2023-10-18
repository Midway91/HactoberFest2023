//SPDX-License-Identifier: MIT
pragma solidity ^0.8.17;

contract HealthRecord
{
    uint public pid=1000;
    
    struct patientDetails
    {
        uint pid;
        string patientName;
        uint age;
        string gender;
        uint phNo;
        string bloodType;
        string location;
        
    }

    struct RecordBlock
    {
        uint pid;
        string hospitalName;
        string doctorName;
        string speciality;
        string referredBy;
        string complaints;
        string investigatinAdvise;
        string medicineAdvice;
    }
    RecordBlock[] public Records;
    mapping (uint=>patientDetails) public Patient;

    function getpid()public view returns(uint){
        return pid;
    }

    function insertPatient(string memory _patientName,uint _age,string memory _gender,uint _phNo,string memory _bloodType,string memory _location)public 
    {
        Patient[pid]=patientDetails(pid,_patientName,_age,_gender,_phNo,_bloodType,_location);
        pid++;
    }

    function insertRecord(uint _pid,string memory _hospitalName,string memory _doctorName,string memory _speciality,string memory _referredBy,string memory _complaints,string memory _investigatinAdvise,string memory _medicineAdvice)public
    {
        RecordBlock memory newrecord;
        newrecord.pid=_pid;
        newrecord.hospitalName=_hospitalName;
        newrecord.doctorName=_doctorName;
        newrecord.speciality=_speciality;
        newrecord.referredBy=_referredBy;
        newrecord.complaints=_complaints;
        newrecord.investigatinAdvise=_investigatinAdvise;
        newrecord.medicineAdvice=_medicineAdvice;

        Records.push(newrecord);
    }

}