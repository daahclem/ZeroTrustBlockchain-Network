const Web3 = require('web3');

// Connect to the local Ganache instance
const web3 = new Web3('http://127.0.0.1:7545');

// ABI of the contract
const abi = [
    {
        "anonymous": false,
        "inputs": [
            {
                "indexed": true,
                "internalType": "address",
                "name": "user",
                "type": "address"
            },
            {
                "indexed": false,
                "internalType": "bool",
                "name": "success",
                "type": "bool"
            }
        ],
        "name": "VerificationOutcome",
        "type": "event"
    },
    {
        "inputs": [
            {
                "internalType": "address",
                "name": "",
                "type": "address"
            }
        ],
        "name": "verifiedUsers",
        "outputs": [
            {
                "internalType": "bool",
                "name": "",
                "type": "bool"
            }
        ],
        "stateMutability": "view",
        "type": "function",
        "constant": true
    },
    {
        "inputs": [
            {
                "internalType": "string",
                "name": "credentials",
                "type": "string"
            }
        ],
        "name": "verifyCredentials",
        "outputs": [
            {
                "internalType": "bool",
                "name": "",
                "type": "bool"
            }
        ],
        "stateMutability": "nonpayable",
        "type": "function"
    },
    {
        "inputs": [
            {
                "internalType": "string",
                "name": "outcome",
                "type": "string"
            }
        ],
        "name": "recordOutcome",
        "outputs": [],
        "stateMutability": "nonpayable",
        "type": "function"
    }
];

// Contract address
const contractAddress = '0xfba248a9906a38c0479fdd4e4446c2ddcf7933bb';

// Create contract instance
const myContract = new web3.eth.Contract(abi, contractAddress);

// Example function to verify credentials
async function verifyUserCredentials(address, credentials) {
    const accounts = await web3.eth.getAccounts();
    const userAccount = accounts[0];

    try {
        const receipt = await myContract.methods.verifyCredentials(credentials).send({ from: userAccount });
        console.log('Credentials verification transaction receipt:', receipt);
        return true;
    } catch (error) {
        console.error('Error verifying credentials:', error);
        return false;
    }
}

// Example function to record an outcome
async function recordVerificationOutcome(address, outcome) {
    const accounts = await web3.eth.getAccounts();
    const userAccount = accounts[0];

    try {
        const receipt = await myContract.methods.recordOutcome(outcome).send({ from: userAccount });
        console.log('Outcome recording transaction receipt:', receipt);
        return true;
    } catch (error) {
        console.error('Error recording outcome:', error);
        return false;
    }
}

// Main function to handle command line arguments
async function main() {
    const args = process.argv.slice(2);
    const action = args[0];
    const address = args[1];
    const param = args[2];

    console.log('Action:', action);
    console.log('Address:', address);
    console.log('Param:', param);

    if (action === 'verify_credentials') {
        const result = await verifyUserCredentials(address, param);
        process.exit(result ? 0 : 1);
    } else if (action === 'record_outcome') {
        const result = await recordVerificationOutcome(address, param);
        process.exit(result ? 0 : 1);
    } else {
        console.log('Unknown action:', action);
        process.exit(1);
    }
}

main().catch(error => {
    console.error('Main function error:', error);
    process.exit(1);
});
