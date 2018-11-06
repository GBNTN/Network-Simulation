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

void Network::resize(const size_t &newsize)
{
    values.resize(newsize);
    RNG.normal(values);
}
 
bool Network::add_link(const size_t &a, const size_t &b)
{
    try {
        if( a==b ) throw std::runtime_error("impossible to links node to itself");
            
        if( a>=values.size() or b>=values.size() ) throw std::runtime_error("One of the nodes doesn't exist");
        
        for(auto const elt : links)
        {
            if((elt.second==a or elt.second==b) and (elt.first==a or elt.first==b))
            {
                throw std::runtime_error("The link already exist");
            }
        }
        links.insert(std::pair<size_t, size_t>(a, b));
        links.insert(std::pair<size_t, size_t>(b, a));
        return true;
    }
    catch(std::runtime_error const& e)
    {
        std::cerr << "Error : " << e.what() << std::endl;
        return false;
    }
}

size_t Network::random_connect(const double& mean_deg)
{
    links.erase(links.begin(), links.end());
    size_t newLinks(0);
    std::vector<size_t> index;
    
    
    for (size_t i(0); i < this->size(); ++i) index.push_back(i);
    
    try {
        for (size_t i(0); i< index.size(); ++i)
        {
            size_t degree(RNG.poisson(mean_deg));
            if(degree > index.size()) throw std::runtime_error("Le nombre de lien est supérieur au nombre de nodes");
            
            RNG.shuffle(index);
            size_t it(0);
            
            for(int n(0); n < degree; ++n)
            {
                while(not add_link(i,index[it]))
                {
                    ++it;
                    continue;
                }
                newLinks++;
            }
        }
    }
    catch(std::runtime_error const& e)
    {
            std::cerr << "Error : " << e.what() << std::endl;
            return 0;
    }
    return newLinks;
}

size_t Network::set_values(const std::vector<double>& newvalues)
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

size_t Network::size() const
{
    return values.size();
}

// We could have use the method of the class : neighbors(_n)
size_t Network::degree(const size_t& _n) const
{
    return links.count(_n);
}

double Network::value(const size_t& _n) const
{
    return values[_n];
}

std::vector<double> Network::sorted_values() const
{
    std::vector<double> tmp(values);
    
    std::sort(tmp.begin(), tmp.end());
    std::reverse(tmp.begin(), tmp.end());
    return tmp;
}


std::vector<size_t> Network::neighbors(const size_t& _n) const
{
    std::vector<size_t> linkednodes;
    auto eql = links.equal_range(_n);
    
    for(auto it = eql.first; it != eql.second; ++it)
    {
        if(it->first == _n) linkednodes.push_back(it->second);
    }
    return linkednodes;
}
