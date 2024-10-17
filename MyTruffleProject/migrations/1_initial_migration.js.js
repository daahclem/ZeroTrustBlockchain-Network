// migrations/1_initial_migration.js
const Migrations = artifacts.require("Migrations");

module.exports = function (deployer) {
  console.log("Starting to deploy Migrations contract");
  deployer.deploy(Migrations).then(() => {
    console.log("Migrations contract deployed");
  }).catch((error) => {
    console.error("Error deploying Migrations contract:", error);
  });
};
