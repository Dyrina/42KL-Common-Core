---
aliases:
tags:
  - status/active
  - project/netpractice
created: 2026-02-11, 16:18
modified: 2026-08-21, 20:57
---
_This project has been created as part of the 42 curriculum by ydylan-k_

<h1 align="center">NetPractice</h1>
<h4 align="center">Discover the basics of networking</h1>

## Description
The project goal is to learn and understand the basics of networking. It introduces IP addresses that connect the devices today to the hardware like routers and switches that connect networks together and enable us to communicate almost immediately cross-continental.

We will be using a network training interface which simulates networking problems with interactive routing tables and subnet configurations for us to resolve them and make the network function properly.

## Instructions
1. Download the interface from the project page on the intra.
2. Extract the tar file and in the command line, run the `./run.sh` or `sh run.sh` to initialise the webserver of the interface.
3. It should automatically reroute you to the interface webpage on your browser, otherwise just go to `http://localhost:49152`.
4. When you first saw the webpage, you will see two options. **Training** and **Evaluation**. In training, you will need to fill in your intra id and solve 10 levels for the project submission. You will need to export each level's configuration for the project submission. To do that, in each level on the top left, you will see a button called `Get my config` which exports a json file which holds the networking configuration you made for the problem. Do that for all 10 levels, name each json file accordingly and must be placed at the root of your submission repository.
5. And for **Evaluation**, it's for during your evaluation where you have to complete 3 random levels from 6 to 10 within 15 minutes.

## Resources
### TCP/IP Addressing
**IP** stands for **Internet Protocol**. An IP address is a unique identifier assigned to a device on a network dictating how data is routed to it. Currently there are two different versions of the protocol in use: **IPv4** and **IPv6**.

#### IPv4
**IPv4** is the most commonly used format, which looks like this:
```
192.168.1.128
```

It is a 32-bit address made up of 4 octets (4 octets * 8 bits = 32 bits). Each octet holds a numerical value ranging from 0 to 255. (An octet simply means a grouping of eight, much like how a standard byte contains 8 bits). Because of this 32-bit limit, the total number of unique addresses that can be represented using **IPv4** is roughly 4.3 billion. It has been the foundational standard for internet routing since it was first introduced in 1981.

#### Legacy IPv4 Classes (Classful Routing)
Before modern CIDR notation (like `/28` or `/24`) existed, the internet used a rigid system called **Classful Routing**. IP addresses were strictly divided into classes (A, B, and C) based on the value of their first octet. This determined their default subnet mask automatically.

The idea behind Classful address assignments was, if you were a company that needed 200 IP addresses, a **/24** IP address block from the **Class C** range would be assigned. Or if you needed 50,000 IP addresses, a **/16** IP address block from **Class B** range would be assigned. Or if you need larger than 65,000~ IP addresses, a **Class A** block would be assigned.[^7]

The system was eventually abandoned because it was highly inefficient and wasted millions of usable IP addresses. For instance, if you only needed 300 IP addresses, a **Class C** would not suffice, so you would end up with a **Class B** and nearly 60,000 IP addresses would be wasted. However, its legacy remains important because it explains exactly why we still treat `/8`, `/16`, and `/24` as the "standard" network boundaries today.

**The IPv4 Class Table**:

| Class       | Classful IP Range                | Subnet Mask for each Block | Number of Blocks | IP addresses per Block | Original Purpose                                  |
| ----------- | -------------------------------- | -------------------------- | ---------------- | ---------------------- | ------------------------------------------------- |
| **Class A** | `1.0.0.0` to `127.255.255.255`   | `255.0.0.0` (**/8**)       | 128              | 16,777,216             | Massive global networks (Millions of hosts)       |
| **Class B** | `128.0.0.0` to `191.255.255.255` | `255.255.0.0` (**/16**)    | 16,384           | 65,536                 | Large enterprises (Thousands of hosts)            |
| **Class C** | `192.0.0.0` to `223.255.255.255` | `255.255.255.0` (**/24**)  | 2,097,152        | 256                    | Small local networks (Up to 254 hosts)            |
| **Class D** | `224.0.0.0` to `239.255.255.255` | N/A                        | N/A              | N/A                    | Reserved for Multicast (One-to-many broadcasting) |
| **Class E** | `240.0.0.0` to `255.255.255.255` | N/A                        | N/A              | N/A                    | Reserved for Experimental/Research purposes       |

*(Note: `127.0.0.0/8` is technically part of the Class A block, but the entire range is permanently reserved for localhost/loopback testing).

#### IPv6
**IPv6** is the next generation IP protocol:
```
2001:0db8:85a3:0000:0000:8a2e:0370:7334
```

It is a 128-bit address made up of 8 groups each containing 16 bits. Each group is represented in hexadecimal characters rather than decimals. Because of the larger 128-bit limit, the total number of unique addresses that can be represented is roughly 340 undecilion addresses (340 * $10^{36}$).

It has been becoming more widespread since it was first introduced back in 1998 as it slowly replaces **IPv4**. It has some advantages over **IPv4**, like for example: SLAAC (Stateless Address Autoconfiguration), Built-In IPsec, and fixed header size. So eventually **IPv4** will become obsolete.

#### Private IP vs Public IP
Public IP addresses act as unique, global identifiers for navigating the wider internet, whereas Private IP addresses are reusable, local identities reserved strictly for internal communication within a home or office network.

| Type         | IPv4 Examples                        | Usage                                    |
| ------------ | ------------------------------------ | ---------------------------------------- |
| **Private**  | 10.x.x.x, 172.16-31.x.x, 192.168.x.x | Home/office internal, no internet access |
| **Public**   | 8.8.8.8, 1.1.1.1                     | Unique on the internet                   |
| **Loopback** | 127.0.0.1 (localhost)                | Access to own device                     |

**RFC 1918 (Private IP Space):** This standard establishes the reserved IP address blocks shown above that are meant exclusively for internal, local networks. Traffic using these private IPs is strictly non-routable on the public internet and will be automatically dropped by internet routers unless translated first (via NAT).

#### Network Address Translation (NAT)
**Network Address Translation** or **NAT** is a technology that converts private IP addresses to public IP addresses and vice versa in order to provide Internet access to the local hosts. NAT generally operates on a router or firewall.

There are 3 types of **NAT** currently out there:
1. **Static NAT**
	- `Internal: 192.168.1.10 ←→ External: 203.0.113.10`
	- Map private IP addresses with public IP addresses on a one-to-one basis.
	- It's used in servers like web-servers or mail-servers.
2. **Dynamic NAT**
	- `Internal IPs → [NAT Pool] → External IPs`
	- Automatically and temporarily maps private IP addresses to available public IP addresses from a registered pool on a one-to-one basis when internal devices request internet access.
	- It is used when we know the number of fixed users who want to access the internet at a given point in time.
	- When the pool is full, any new connection request will be dropped or blocked by the router.
3. **Port Address Translation (PAT)**
	- ```
	  192.168.1.10:5000 → 203.0.113.5:40001
	  192.168.1.11:5000 → 203.0.113.5:40002
	  192.168.1.12:5000 → 203.0.113.5:40003
	  ```
	- Private IP addresses can be translated to a single public IP address by using port numbers. The port numbers are used to distinguish the traffic, i.e., which traffic belongs to which private IP address.
	- Also known as **NAT Overload**
	- Because Private IP addresses cannot route over the public internet; routers use **PAT** to share a single public IP among multiple local devices.
	- **Carrier-Grade NAT (CGNAT):** A massive deployment of PAT by ISPs. It maps thousands of customer routers or cellular endpoints (using `100.64.0.0/10` private range) to a single public IP, creating a "Double NAT" that saves IPv4 addresses but breaks port forwarding.

#### Dynamic Host Configuration Protocol (DHCP)
**Dynamic Host Configuration Protocol** or **DHCP** provides automatic IP addresses and network configuration to devices. Without it, you would need to manually assign the IP addresses to your devices which becomes tedious on larger networks.

**Configuration Example:**

| Information     | Example       |
| --------------- | ------------- |
| IP Address      | 192.168.1.100 |
| Subnet Mask     | 255.255.255.0 |
| Default Gateway | 192.168.1.1   |
| DNS Server      | 8.8.8.8       |
| Lease Time      | 24 hours      |

**DORA Process**
DHCP works in 4 steps (DORA):

1. **Discover**
```
Client → "Looking for IP!" → Broadcast
```
2. **Offer**
```
DHCP Server → "192.168.1.100 available" → Client
```
3. **Request**
```
Client → "I want 192.168.1.100" → Server
```
4. **Acknowledge**
```
Server → "OK, it's yours for 24 hours" → Client
```

#### Domain Name System (DNS)
**Domain Name System** or **DNS** is a system that uses servers to maintain a table that contains the domain name and its IP address. People can type in the domain name, and the DNS server will handle the conversion into the IP address for the computer to connect with the web server. It's usually seen as the phonebook of the internet.

For example: The IP address `8.8.8.8` routes to Google's Public DNS server to translate domain names into IP addresses.

**DNS Record Types**:

| Record    | Description  | Example                     |
| --------- | ------------ | --------------------------- |
| **A**     | IPv4 address | example.com → 93.184.216.34 |
| **AAAA**  | IPv6 address | IPv6 format                 |
| **CNAME** | Alias        | www → example.com           |
| **MX**    | Mail server  | mail.example.com            |
| **TXT**   | Text info    | For verification            |
[List of DNS Record Types](https://en.wikipedia.org/wiki/List_of_DNS_record_types)

#### Internet Protocol Suite
The **Internet Protocol Suite** or also known as the **TCP/IP Suite** is the foundational family of protocols that powers the internet. It acts as a massive toolbox containing everything from addressing (IP) to application tools (DNS and DHCP). But to actually move the data from point A to point B, the suite relies on two primary transport protocols: **TCP & UDP**.

#### TCP & UDP (Transfer Protocol)
When data is actually transported across the network, it generally uses one of the two transfer protocols from the suite:

**Transmission Control Protocol (TCP)**
**TCP** is a transport protocol that provides reliable, ordered, error-checking delivery stream of data between devices. It uses a **3-Way Handshake** to initialise the connection between the devices. Ensures that the packets are send in order, and if there's any lost packets, it will resend the message until the receiving device has acknowledged that the packaged has been received.

TCP Connection Setup:
```
Client         Server
  |--- SYN --->|
  |<-- SYN+ACK-|
  |--- ACK --->|
  [Connection OK]
```

TCP Data Transmission:
```
Data 1 →→→ ACK 1
Data 2 →→→ ACK 2
Data 3 →→→ LOST!
Data 3 →→→ ACK 3 (Resend)
```

**User Datagram Protocol (UDP)**
**UDP** is another transport protocol that provides fast transmission as there's no checking of any kind. It's just transfer the data directly to the receiving device in a constant stream without stopping to check if the receiver fails to receive some of the packets.

```
Data 1 →→→ ✓
Data 2 →→→ ✓
Data 3 →→→ ✗ (Lost, no retry)
Data 4 →→→ ✓
```

### Subnet Masks
#### Subnetting Basics
Subnetting is the process of dividing a single large network into multiple smaller networks. This practice makes far more efficient use of available IP addresses, isolates networks from one another for security, reduces unnecessary broadcast traffic, and creates a much more organized network infrastructure.

#### Subnet Masks & Classless Inter-Domain Routing (CIDR) Notation
An IP address alone doesn't tell a router where a network ends and where the local devices begin. To determine this, we use a **Subnet Mask**. The mask acts as a filter, splitting the IP address into two distinct pieces: the **Network Part** (the overarching group) and the **Host Part** (the specific device).

Writing out full subnet masks like `255.255.255.0` can be tedious, so modern networking uses **CIDR Notation** (Classless Inter-Domain Routing). CIDR provides a shorthand slash (like `/24`) that represents the exact number of consecutive binary `1`s used to define the network portion of the address.

**Network & Host Part:**
```
[Network Part][Host Part]
192.168.1    .100
Network addr  Device addr
```

The subnet mask separates network and host part:

| Subnet Mask     | CIDR | Network Bits | Host Bits |
| --------------- | ---- | ------------ | --------- |
| 255.0.0.0       | /8   | 8            | 24        |
| 255.255.0.0     | /16  | 16           | 16        |
| 255.255.255.0   | /24  | 24           | 8         |
| 255.255.255.128 | /25  | 25           | 7         |
| 255.255.255.192 | /26  | 26           | 6         |

**CIDR Notation:**
```
192.168.1.0/24
            ↓
         24 bits network
          8 bits host
```

/24 Example:
```
Mask: 255.255.255.0
Binary: 11111111.11111111.11111111.00000000
        ←── 24 bits ──→←── 8 bits ──→
        Network         Host
```

#### Host Calculation
To calculate the number of usable host addresses is: $2^{n}$ - 2 = number of usable hosts
$n$ represents the number of host bits.

| CIDR | Host Bits | Total | Usable |
| ---- | --------- | ----- | ------ |
| /24  | 8         | 256   | 254    |
| /25  | 7         | 128   | 126    |
| /26  | 6         | 64    | 62     |
| /27  | 5         | 32    | 30     |
| /28  | 4         | 16    | 14     |
| /29  | 3         | 8     | 6      |
| /30  | 2         | 4     | 2      |

**Key Subnetting Rules**
- **The "-2" Rule (Host Calculation):** You can never use all IP addresses in a subnet. The very first IP is always reserved for the **Network Address or ID**, and the very last IP is always reserved for the **Broadcast Address**.
- **Subnet Boundaries:** The CIDR notation dictates block sizes. For example, a `/18` operates in the 3rd octet creating blocks of 64, while a `/28` operates in the 4th octet creating blocks of 16.
- **The `.0` Anomaly:** While an IP ending in `.0` is strictly the Network ID in standard networks (like a `/24`), it can actually be a valid, assignable host IP in larger, multi-octet subnets (like a `/16`).

**Common Routing & Troubleshooting Fixes**
- **Invalid Gateways:** A host device's default gateway must _exactly_ match the IP address of the router interface on its local subnet.
- **Subnet Overlaps:** If a host network accidentally swallows a router's point-to-point link, shrink the subnet mask (e.g., change a `/25` to a `/27`) to separate them.
- **Syntax Errors:** Static routes must always point to the overarching **Network ID** (never an individual Host IP) and be directed toward a valid next-hop router IP.
- **Dropped Return Traffic:** If traffic leaves but doesn't come back, widen the return route envelope (e.g., expanding a `/26` back to a `/24`) to ensure all internal subnets are covered.
- **Route Summarization:** You can use wider masks to create an "umbrella" route that efficiently covers multiple downstream subnets with a single rule.
- **Routing Loops:** If traffic bounces endlessly between routers, find and delete any overly specific or conflicting manual static routes.

**Example: /26 Subnetting**
Let's divide 192.168.1.0/24 into 4 subnets:

| Subnet | Network       | Host Range  | Broadcast     |
| ------ | ------------- | ----------- | ------------- |
| 1      | 192.168.1.0   | .1 - .62    | 192.168.1.63  |
| 2      | 192.168.1.64  | .65 - .126  | 192.168.1.127 |
| 3      | 192.168.1.128 | .129 - .190 | 192.168.1.191 |
| 4      | 192.168.1.192 | .193 - .254 | 192.168.1.255 |

#### Network Address & Broadcast Address
- **Network Address (The First IP):** Used by routers to identify the subnet itself. It represents the entire network block.  
- **Broadcast Address (The Last IP):** Used to send a single message to all devices on that specific subnet simultaneously.

For example, in a `192.168.1.0/24` network, `.0` is the Network ID, `.255` is the Broadcast Address, leaving `.1` through `.254` as usable IPs for actual devices.

### Default Gateways
A default gateway serves as the exit point for a local network. When a device needs to communicate with an IP address that sits outside of its own subnet, it cannot deliver the data directly. Instead, the device forwards the data to its default gateway (usually the local router). The gateway acts as a bridge, taking the internal traffic and routing it out toward external networks or the global internet.

**The Default Route (`0.0.0.0/0` & `default`)** When you configure a default gateway on a router, you are essentially programming a "catch-all" route. You will often see this written in two different ways depending on the system:
- **`0.0.0.0/0`**: This is the actual mathematical CIDR notation. The `/0` means "zero bits need to match," which mathematically includes every single IPv4 address in existence. If the router doesn't have a specific route for a destination, the traffic falls into this bucket.  
- **`default`**: This is simply a text shortcut (or alias) used by router operating systems—and your network simulator—to make that specific `0.0.0.0/0` route easier for humans to read and type.

#### Internet
The **Internet** is the largest **WAN** in the world. It connects all the **WAN** networks in the world which in turn lets us be able to message someone from other countries. And nobody owns it!

```
[Home LAN] ←→ [ISP] ←→ [Internet Backbone] ←→ [Target Server]
```

#### Static vs Dynamic Routing 
To forward traffic correctly, a router relies on a routing table (its internal map). This map can be built in two different ways:

**1. Static Routing**
- Routes are manually configured by a network administrator.
- It's best for small networks where the layout rarely changes.
- It's highly stable, reliable, and secure. It requires almost zero CPU power or network bandwidth because the router doesn't have to calculate anything or chat with other routers.
- **Example Syntax:** `ip route 10.0.0.0/8 192.168.1.254` _(Meaning: To reach the 10.x.x.x network, hand the traffic to the router at 192.168.1.254)._

**2. Dynamic Routing**
- Routers automatically talk to each other to map the network. If a cable gets cut or a line breaks, they automatically calculate a new path on the fly.
- It's best for large, complex enterprise networks that require high availability and redundancy.
- Uses more router memory, CPU power, and network bandwidth to constantly broadcast and process routing updates.

**Common Protocols:**
    - **RIP:** An older protocol generally used for small networks.
    - **OSPF:** The industry standard for medium to large enterprise networks.
    - **BGP:** The massive, highly scalable protocol used to route the internet backbone.

**Host Routes (`/32`):** While standard routes direct traffic to an entire subnet, you can use a `/32` subnet mask to create a highly specific route for a _single_ IP address. Because routers always prioritize the most specific route available, a `/32` can be used to override a general rule (for example, forcing all DNS traffic for `8.8.8.8` to take a very specific gateway, while everything else uses the default route).

#### Virtual Private Network (VPN)
A **Virtual Private Network** or **VPN** creates a secure, encrypted tunnel over the public internet.

Normally, Private IPs (like homes or office networks) are not allowed to cross the public internet. A **VPN** solves this by wrapping your private data inside a public IP packet. It then securely "tunnels" that data across the internet to another route, where it is unwrapped and delivered. This allows remote workers or devices to securely access an internal office or home network from anywhere in the world.

```
[Your PC] ══════════════════════════ [Company Network]
             Encrypted Tunnel (VPN)
             Over the Internet
```

### Routers & Switches
#### LAN vs WAN
Networks are generally categorized by their physical footprint and who owns the infrastructure:

**LAN (Local Area Network)** 
A LAN defines a network that is small in physical scope, such as a home network, a single office building, or a LAN cafe. Because the physical distance is short and the hardware is privately owned by the user, LANs typically offer very high network speeds and extremely low latency.

**WAN (Wide Area Network)**
A WAN covers a much larger geographic area by connecting multiple isolated LANs together. Examples include a corporation connecting its branch offices across different cities, or server architectures spanning across countries. Because of the vast distances and massive infrastructure required, WANs are usually built, controlled, and maintained by Internet Service Providers (ISPs), and generally experience higher latency than a LAN.

#### Modem & Firewall
**Modem**
A modem is a device that connects your home network to the internet, usually provided from the ISP (Internet Service Provider). It converts digital data from your devices into analog signals for utility lines, and vice versa. It acts as a bridge that connects your house or office directly to your ISP who would route your data to the wider internet. 

**Firewall**
A firewall is a security gate that controls network traffic based on predetermined rules. By default, it blocks all unauthorized traffic unless explicitly configured to allow it.

**Types of Firewalls**
- **Packet Filtering:** Fast, basic filtering based only on IPs and ports.
- **Stateful:** Tracks active connection states to make context-aware decisions.
- **Application Layer:** Analyzes deep application-level data (e.g., HTTP/FTP content).
- **Next-Gen (NGFW):** Enterprise devices combining all the above with IPS and antivirus.

**Software vs Hardware Firewall

| Feature        | Software Firewall | Hardware Firewall   |
| -------------- | ----------------- | ------------------- |
| **Where?**     | On computer       | At network edge     |
| **Protection** | Single device     | Entire network      |
| **Example**    | Windows Firewall  | Cisco ASA, Fortinet |
| **Cost**       | Low/free          | High                |
| **Management** | Easy              | Expertise needed    |

**Example Rule List**
It's processed top-to-bottom, it stops reading once a rule matches. "Deny All" must go last.

| Order | Source   | Destination | Port    | Action |
| ----- | -------- | ----------- | ------- | ------ |
| 1     | Any      | Web Server  | 80, 443 | Allow  |
| 2     | Admin PC | Any         | Any     | Allow  |
| 3     | Any      | Any         | 22      | Deny   |
| 4     | Any      | Any         | Any     | Deny   |

**Demilitarized Zone (DMZ)**
A DMZ isolates public-facing servers from the internal network.

```
Internet → [External Firewall] → DMZ (Web Servers) ← [Internal Firewall] ← Internal LAN
```

Servers in the DMZ can be accessed from the internet, but are blocked from accessing the internal LAN. If a DMZ server is compromised, the internal network remains perfectly secure.

#### Router
A router's primary job is to connect different networks together and determine the best path for forwarding data. While home routers act as an all-in-one gateway (handling routing, NAT, DHCP, and a basic firewall), enterprise routers are dedicated strictly to high-performance traffic management.

**The Routing Process & Logic**
1. A packet arrives, and the router reads the Destination IP.
2. The router checks its internal **Routing Table**.
3. It applies the **Longest Prefix Match** rule, meaning the most specific route (the longest subnet mask) always wins.
4. If the destination doesn't match any specific network, it is forwarded to the default catch-all route (`0.0.0.0/0`).
5. The packet is sent out the designated exit interface.

**Example Routing Table**

| **Destination Network** | **Exit Interface** | **Next Hop**       |
| ----------------------- | ------------------ | ------------------ |
| `192.168.1.0/24`        | `eth0`             | Directly Connected |
| `10.0.0.0/8`            | `eth1`             | `192.168.1.254`    |
| `0.0.0.0/0`             | `eth2`             | ISP Gateway        |

#### Hub & Switch
**Hub** is a hardware that can connect multiple devices.
But one thing about it is that all data that was send by a device is broadcast to the other devices. Collision may occur when more than one device is sending data. Which requires the senders to resend the data.

All the devices that are connected will shared the same bandwidth of the hub.

```
       Hub
    /  |  \
  PC1 PC2 PC3

PC1 → Hub → Send to everyone (broadcast)
```

**Switch** keeps a table of **MAC addresses** of all connected devices. It sends to the destination port by observing the header of the packet for the **MAC address** of the sender to compare it to its own table.

Each port has its own collision domain, and it has their own dedicated bandwidth. And it's more secure because the data is only send to the receiver device port.

```
       Switch (MAC Table)
    /    |    \
  PC1   PC2   PC3

PC1 → Switch → Send only to PC2 (unicast)
```

**Switching Loops:** Happens when extra cables connect the same switches, causing data to spin in circles forever and crash the network. This is prevented by the **Spanning Tree Protocol (STP)**, which automatically turns off the extra cables.

#### MAC Address (Media Access Control)
A **MAC (Media Access Control) Address** is a unique, physical address permanently assigned to a network device by its manufacturer.

**MAC vs. IP Addresses**
- **IP Address (Logical):** Identifies _where_ you are connected to the network. (Like a temporary mailing address).
- **MAC Address (Physical):** Identifies _what_ the specific piece of hardware is. (Like a permanent fingerprint).

When your device connects to the network, the router uses your device's unique MAC address to hand out an IP address and keeps a table linking the two together so it knows exactly which hardware has which IP.

**Example MAC Address:** `00:1A:2B:3C:4D:5E` _(It is a 48-bit address written as six pairs of hexadecimal digits, usually separated by colons or hyphens)._

#### Address Resolution Protocol (ARP)
While IP addresses are required to route data across the internet, local network hardware (like switches) only understands physical MAC addresses. **ARP is the protocol that bridges the two.** Its entire job is to translate a known IP address into an unknown MAC address.

**How It Works (The ARP Request)**
1. **The Broadcast:** If your computer wants to send data to `192.168.1.50` but only knows the IP, it sends a broadcast message to every device on the local network asking: _"Who has IP 192.168.1.50?"_
2. **The Reply:** The specific device holding that IP responds directly, saying: _"That's me, and here is my MAC address."_
3. **The ARP Table:** Your computer saves this IP-to-MAC pairing in its internal cache (the ARP Table) so it can communicate directly with that device next time without having to ask.

### OSI Layers
#### What Is A Network?
At its simplest, a network is created whenever two or more devices are connected together to share resources and communicate with each other.

**Networks in Daily Life** We interact with complex networks constantly without thinking about the underlying infrastructure. Common examples include:
- **Online Messaging:** Routing text data instantly between mobile devices.
- **Video Streaming:** Receiving heavy video data packets from a distant server to your screen.
- **Online Multiplayer:** Syncing real-time game data between dozens of players simultaneously.
- **Voice Calls (VoIP):** Converting live voice audio into data packets and sending them across the world with zero delay.

#### OSI Model (Open Systems Interconnection)
The Open Systems Interconnection (OSI) Model divides network communication into 7 distinct layers. This standardization allows devices from different manufacturers to communicate and makes troubleshooting much easier by isolating problems to a specific layer.

**7. Application (The User Interface)** Where applications directly access the network.
- _Example:_ Your browser requesting `google.com`.
- _Key Protocols:_ HTTP (80), HTTPS (443), FTP (21), SSH (22), DNS (53).
**6. Presentation (Formatting & Encryption)** Translates, compresses, and encrypts data into a usable format.
- _Example:_ SSL/TLS encrypting a message, or rendering a JPEG image.
**5. Session (Connection Management)** Opens, maintains, and securely closes communication sessions.
- _Example:_ Using cookies to keep you logged into an account as you navigate between different web pages.
**4. Transport (Data Delivery)** Manages how data is transmitted between source and destination ports.
- _TCP:_ Reliable, ordered, checks for errors (e.g., loading web pages).
- _UDP:_ Fast, no error checking (e.g., live video streaming).
**3. Network (Routing & Logical Addressing)** Handles routing data across multiple different networks.
- _Hardware/Addressing:_ **Routers** operate here using **IP Addresses**.
**2. Data Link (Local Switching & Physical Addressing)** Handles data transfer between devices on the _same_ local network. It bridges the software (LLC) to the hardware (MAC).
- _Hardware/Addressing:_ **Switches** operate here by reading **MAC Addresses** to forward traffic to the correct physical port.
**1. Physical (Hardware & Signals)** The physical transmission medium. It converts data into raw binary (1s and 0s) and transmits it as electrical signals, light pulses, or radio waves across cables and connectors.

#### TCP/IP Model
While the OSI model is a 7-layer theoretical concept, the **TCP/IP Model** is the practical, 4-layer architecture actually used to power the internet today.

**The 4 Layers**
- **4. Application:** Combines OSI's top three layers (Application, Presentation, Session).
- **3. Transport:** Handles end-to-end delivery (TCP and UDP).
- **2. Internet:** Handles routing and IP addressing (IP, ICMP, ARP).
- **1. Network Access:** Combines OSI's bottom two layers (Data Link and Physical).

#### Encapsulation
**Encapsulation** is the process of wrapping data with necessary headers or trailers as it moves down the network layers (like putting a letter inside an envelope, and then putting that envelope inside a shipping box). Each layer adds its own specific routing and protocol information.

As data moves down the layers, its official name changes based on what has been wrapped around it:
- **Segment (Transport Layer):** The original data is wrapped with a header containing Source and Destination Ports (TCP/UDP).
- **Packet (Network Layer):** The Segment is wrapped with a header containing the Source and Destination IP Addresses.
- **Frame (Data Link Layer):** The Packet is wrapped with a header and trailer containing the physical MAC Addresses.

![Encapsulation Example|600](https://static.afteracademy.com/images/what-is-data-encapsulation-in-networking-process-148532037a490a19.jpg)

**Decapsulation** is simply the exact reverse. When the data arrives at its destination, the receiving device strips away the headers and trailers layer by layer as the data moves back up the stack until the original message is revealed.

#### HTTP/HTTPS (HyperText Transfer Protocol (Secure))
**HTTP (HyperText Transfer Protocol)** is the protocol used to transfer web data between a client (your browser) and a web server. It operates on a simple **Request-Response Model**:

```
Client → HTTP Request → Server
Client ← HTTP Response ← Server
```
- **Client:** Sends an HTTP Request
- **Server:** Processes and returns an HTTP Response

**HTTPS (Secure HTTP)**
HTTPS is the secure, encrypted version of HTTP.
- **Ports:** Plain HTTP uses port **80**, while HTTPS uses port **443**.
- **Security:** It uses SSL/TLS encryption to scramble the traffic between the client and server, ensuring that sensitive data (like passwords) cannot be intercepted or read by attackers on the network.

### How AI was used in this project?
AI was used to understand the networking concepts and how subnet masks actually works because I had a hard time trying to implement it. And it's used additionally to format this README with information supplemented from my notes.
