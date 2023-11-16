pragma solidity >=0.7.0;

contract Bank{
    mapping (address => uint) user_acc;
    mapping (address => bool) user_exists;

    function create_acc() public payable returns (string memory){
        require(user_exists[msg.sender]==false,"Account already exists!");
        user_acc[msg.sender] = msg.value;
        user_exists[msg.sender] = true;
        return "Account created successfully!";
    }

    function deposit(uint amt) public payable returns (string memory){
        require(user_exists[msg.sender] == true,"Account does not exists!");
        require(amt>0,"Amount should be greater than 0!");
        user_acc[msg.sender] += amt;
        return "Amount deposited successfully!";
    }

    function withdraw(uint amt) public payable returns (string memory){
        require(user_exists[msg.sender] == true,"Account does not exists!");
        require(amt>0,"Amount should be greater than 0!");
        require(amt<user_acc[msg.sender],"Insufficient Funds!");
        user_acc[msg.sender] -= amt;
        return "Amount withdrawn successfully!";
    }

    function check_user() public view returns (string memory){
        return user_exists[msg.sender] == true ? "Account exists!" : "Account does not exist!";
    }

    function check_balance() public view returns (uint){
        return user_acc[msg.sender];
    }
}