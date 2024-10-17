ZeroTrustBlockchain-Network

Project Overview

The ZeroTrustBlockchain-Network is a simulation-based project that integrates Zero Trust Architecture and Blockchain Technology to enhance security in financial networks. This project is aimed at addressing advanced threats, such as insider attacks, Advanced Persistent Threats (APTs), and Distributed Denial-of-Service (DDoS) attacks, by implementing a hybrid access control system and decentralized authentication mechanisms.

Key Features

1.	Zero Trust Security Model:
o	Continuous authentication and strict, dynamic access controls.

o	Elimination of implicit trust within network boundaries.

o	Identity and Access Management (IAM) enhanced by multi-factor authentication (MFA).

3.	Blockchain Integration:
o	Immutable ledger ensuring data integrity, non-repudiation, and robust audit trails.

o	Ethereum-based decentralized authentication and smart contract execution.

o	Protection against unauthorized access and tampering of transaction logs.

4.	OMNeT++ Simulation:
   
o	Simulates real-time network behaviors and evaluates security postures under various attack scenarios.

o	Evaluates policy enforcement, insider threats, and system resilience.

Prerequisites

Blockchain

•	Ganache must be running to simulate the blockchain network for decentralized authentication. This project uses Ganache for Ethereum-based simulations, and the blockchain network must be operational before running blockchain-related simulations in OMNeT++.
Web3 Integration

•	The TestWeb3 folder connects the blockchain network via Web3.js to the OMNeT++ simulations.

•	MyTruffleProject contains the smart contracts, but note that MyTruffleProject should remain separate from the main OMNeT++ project folder. Ensure it is properly configured for Ethereum smart contracts.

Project Structure

•	/MyTruffleProject: Contains Truffle files, smart contracts, and blockchain interaction scripts.

•	/TestWeb3: Connects the OMNeT++ simulation to the blockchain network.

•	/simulations: Includes the OMNeT++ simulation configurations for evaluating the Zero Trust framework's performance.

•	/src: Contains source code for various modules such as device security, network firewalls, and blockchain interactions.

How to Run

1.	Ensure Ganache is Running: Open Ganache and configure it to simulate the Ethereum blockchain locally.
   
3.	Truffle Setup:
   
o	Navigate to the MyTruffleProject directory.

o	Compile and deploy the smart contracts:

bash
Copy code
truffle compile
truffle migrate

5.	Run OMNeT++ Simulation:
   
o	Use OMNeT++ IDE to load the ZeroTrustBlockchain-Network project.

o	Ensure that TestWeb3 is properly connected to the Web3.js blockchain.

o	Run the simulations to evaluate the security framework under attack scenarios such as insider threats, MITM attacks, and DDoS attacks.

Key Components

1.	Identity and Access Management (IAM):
   
o	Authentication is decentralized via blockchain, using smart contracts to manage and verify user credentials.
o	Multi-factor authentication is required for sensitive operations.

3.	Hybrid Access Control:
o	Combines RBAC (Role-Based), ABAC (Attribute-Based), DAC (Discretionary), and MAC (Mandatory) access controls to manage permissions.

o	Smart contracts are used to log and enforce access policies, ensuring transparency and non-repudiation.

5.	Network Security:
   
o	External and internal firewalls, intrusion detection systems (IDS), and micro-segmentation are implemented to control network access and detect threats.

o	Data loss prevention (DLP) mechanisms are employed to protect sensitive information in transit.

7.	Blockchain for Audit Trails:
   
o	Critical security events such as access attempts and authentication logs are stored on the blockchain to ensure an immutable record of security decisions.
Simulation Scenarios

•	Man-in-the-Middle Attacks (MITM): Evaluates the system’s ability to maintain data integrity and detect unauthorized interceptions.

•	DDoS Attacks: Tests system throughput, packet loss rates, and latency under large-scale attack conditions.

•	Insider Threats and Malware: Simulates internal network threats and assesses detection and response capabilities.

•	Policy Enforcement and Access Control: Measures the efficiency of policy evaluations and the accuracy of access control decisions.
Results

•	Enhanced detection accuracy and resistance to insider threats.

•	Improved scalability and reduced false positives and negatives.

•	Secure and verifiable transaction handling through the Ethereum blockchain.


