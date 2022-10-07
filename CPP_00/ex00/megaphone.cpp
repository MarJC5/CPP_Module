/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:08:51 by jmartin           #+#    #+#             */
/*   Updated: 2022/10/07 07:44:48 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            for (size_t j = 0; j < strlen(argv[i]); j++)
                std::cout << (char) toupper(argv[i][j]);
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return(0);
}