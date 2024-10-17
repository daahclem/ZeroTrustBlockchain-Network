// migrations/2_deploy_contracts.js
const MyContract = artifacts.require("MyContract");

module.exports = function (deployer) {
  console.log("Starting to deploy MyContract");
  deployer.deploy(MyContract).then(() => {
    console.log("MyContract deployed");
  }).catch((error) => {
    console.error("Error deploying MyContract:", error);
  });
};
