const Web3 = require('web3');

// Connect to the local Ganache instance using a provider
const web3 = new Web3(new Web3.providers.HttpProvider('http://127.0.0.1:7545'));

async function testConnection() {
    try {
        const accounts = await web3.eth.getAccounts();
        console.log('Accounts:', accounts);
    } catch (error) {
        console.error('Error:', error);
    }
}

testConnection();
