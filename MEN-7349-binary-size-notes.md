
(lists below are not comprehensive)

# Overview

The resulting code contains the most of the client:
* State Machine
* Artifact parsing
* API calls (inc auth)
* Configuration library (it would go out)
* JSON library (the platform code is header only)
* HTTP resume
* ...

# Parts replaced

* D-Bus interface replaced with direct linking to mender_auth_api_auth

# Interfaces stubbed out

* HTTP
* tar library
* crypto (artifact sha and key management)
* Key Store database
* Inventory parser
* ...

# Parts commented out

* artifact/v3/scripts
* ...
