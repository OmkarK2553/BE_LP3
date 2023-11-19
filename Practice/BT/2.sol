// SPDX-License-Identifier: GPL-3.0

pragma solidity >=0.7.0;

contract Student_Data{
    struct Student{
        uint sid;
        string name;
        string dept;
    }
    mapping(uint => bool) exists;

    Student[] Students;

    function add_student(uint id,string memory n,string memory d) public {
        require(exists[id]==false,"Student already exists!");
        Student memory new_stud = Student(id,n,d);
        Students.push(new_stud);
        exists[id] = true;
    }

    function get_student(uint id) public view returns (string memory,string memory){
        for(uint i=0;i<Students.length;i++){
            if(Students[i].sid==id){
                return (Students[i].name,Students[i].dept);
            }
        }
        return ("DNE","DNE");
    }

    function get_all() public view returns (uint[] memory,string[] memory,string[] memory){
        uint[] memory sids = new uint[](Students.length);
        string[] memory names = new string[](Students.length);
        string[] memory depts = new string[](Students.length);

        for(uint i=0;i<Students.length;i++){
            sids[i] = Students[i].sid;
            names[i] = Students[i].name;
            depts[i] = Students[i].dept;
        }
        return (sids,names,depts);

    }

    fallback() external payable{
        Students.push(Student(7,"xyz","ce"));
     }
}

contract sender{
    function callfallback(address payable to) public payable{
        (bool sent,)=to.call{value:msg.value}("");
        require(sent,"Failed to send ");
    }
}