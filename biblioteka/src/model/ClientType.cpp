//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 03.12.2019.
//

#include "model/ClientType.h"

using namespace std;

ClientType::ClientType() = default;

ClientType::~ClientType() = default;

const int ClientType::getNumOfRentalVehicles() const {
    return 0;
}

std::string ClientType::getClientType() const{
    string clientTypeInfo;
    clientTypeInfo.append("Typ klienta: ");
    return clientTypeInfo;
}

const double ClientType::getDiscount(double RentPrice) const {
    return 0;
}



