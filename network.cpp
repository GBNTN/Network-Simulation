//
//  network.cpp
//  
//
//  Created by Nathan GIRARD on 22.10.18.
//

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include "network.h"
#include "random.h"

/**
links.first :  index du node1
links.second : index du node auquel node1 est lié
**/

void Network::resize(const size_t &newsize)           // V
{
    values.resize(newsize);
    // RNG.normal(values);
    std::vector<double> newVect(values);
    RNG.normal(newVect);
    values=newVect;
}

// erreur de conception : on ne teste que le premier lien de a et le premier lien de b
// --> or les values peuvent avoir plusieurs liens, le premier n'est pas forcément avec
// b et vice versa
bool Network::add_link(const size_t &a, const size_t &b)        // V
{
    if(a==b or a>=values.size() or b>=values.size()) return false;
    
    for(auto const elt : links)
    {
        if((elt.second==a or elt.second==b) and (elt.first==a or elt.first==b))
        {
            return false;       // find if the link already exists
        }
    }
    links.insert(std::pair<size_t, size_t>(a, b));
    links.insert(std::pair<size_t, size_t>(b, a));
    return true;
}

size_t Network::random_connect(const double& mean_deg)
{
    size_t newlinks(0);
    links.erase(links.begin(), links.end());
    
    for(size_t i(0); i < values.size(); ++i)
    {
        size_t degree = RNG.poisson(mean_deg);
        
        for(size_t j(0); j < degree; ++j)
        {
            while( not add_link(i, RNG.uniform_double(0,(*this).size()))) continue;
            ++newlinks;
        }
    }
    return newlinks;
    
}

size_t Network::set_values(const std::vector<double>& newvalues)    // V
{
    size_t number(0);
    if(values.size() <= newvalues.size())
    {
        for(size_t i(0); i < values.size(); ++i)
        {
            values[i] = newvalues[i];
        }
        number = values.size();
    }
    
    if(values.size() > newvalues.size())
    {
        for(size_t i(0); i < newvalues.size(); ++i)
        {
            values[i] = newvalues[i];
        }
        number = newvalues.size();
    }
    
    return number;
}

size_t Network::size() const                        // V
{
    return values.size();
}

size_t Network::degree(const size_t& _n) const      // V
{
    return links.count(_n);
    // std::vector<size_t> tmp(this->neighbors(_n));
    // return tmp.size();
}

double Network::value(const size_t& _n) const       // V
{
    return values[_n];
}

std::vector<double> Network::sorted_values() const // V
{
    std::vector<double> tmp(values);
    
    std::sort(tmp.begin(), tmp.end());
    std::reverse(tmp.begin(), tmp.end());
    return tmp;
}


std::vector<size_t> Network::neighbors(const size_t& _n) const  // V
{
    std::vector<size_t> linkednodes;
    auto eql = links.equal_range(_n);
    
    for(auto it = eql.first; it != eql.second; ++it)
    {
        if(it->first == _n) linkednodes.push_back(it->second);
    }
    return linkednodes;
}

/**
std::vector<size_t> Network::neighbors(const size_t& _n) const  // V
{
    std::vector<size_t> linkednodes;
    
    for(auto it = links.begin(); it != links.end(); ++it)
    {
        while(it->first == _n)        // Les noeuds sont rangés par ordre de l'indice qu'ils ont.
        {                               // --> Ainsi on évite de faire des boucles surperflues.
            linkednodes.push_back(it->second);
            ++it;
        }
    }
    return linkednodes;
}
*/
