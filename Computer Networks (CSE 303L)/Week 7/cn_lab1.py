Program 1: Write a program to display the class of IP address, network mask and generate the subnet IP address based on the subnet bits entered from the keyboard. 

#include <iostream>
#include <vector>
#include <bitset>

std::string get_class(char ip[]) {
    int i = 0;
    while (ip[i] != '.') {
        i++;
    }
    int ip_class = atoi(ip);
    if (ip_class >=0 && ip_class <= 127)
        return "A";
    else if (ip_class >= 128 && ip_class <= 191)
        return "B";
    else if (ip_class >= 192 && ip_class <= 223)
        return "C";
    else if (ip_class >= 224 && ip_class <= 239)
        return "D";
    else if (ip_class >= 240 && ip_class <= 255)
        return "E";
}

std::string get_subnet_mask(int subnet_bits) {
    std::string subnet_mask = "";
    for (int i = 0; i < subnet_bits; i++)
        subnet_mask += "1";
    while (subnet_mask.length() < 32)
        subnet_mask += "0";
    std::string subnet_mask_ip = "";
    for (int i = 0; i < 32; i += 8) {
        std::bitset<8> bits(subnet_mask.substr(i, 8));
        subnet_mask_ip += std::to_string(bits.to_ulong()) + ".";
    }
    return subnet_mask_ip.substr(0, subnet_mask_ip.length()-1);
}

int main() {
    char ip[17];
    int subnet_bits;
    std::cout << "Enter IP address: ";
    std::cin >> ip;
    std::cout << "Enter number of subnet bits: ";
    std::cin >> subnet_bits;
    std::cout << "Class of the IP Address: " << get_class(ip) << std::endl;
    std::cout << "Subnet Mask: " << get_subnet_mask(subnet_bits) << std::endl;
    return 0;
}