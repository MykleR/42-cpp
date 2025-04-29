/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:43:00 by mykle             #+#    #+#             */
/*   Updated: 2025/04/29 14:12:33 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


int main(void) {
  DiamondTrap oui("ABOMINATION");
  std::cout << "DiamondTrap name: " << oui.getName() << std::endl;
  std::cout << "Hit points: " << oui.getHitPoints() << std::endl;
  std::cout << "Energy points: " << oui.getEnergyPoints() << std::endl;
  std::cout << "Attack damage: " << oui.getAttackDamage() << std::endl;
  std::cout << std::endl;
  oui.attack("TARGET");
  std::cout << std::endl;

  oui.attack("TARGET");
  oui.guardGate();
  oui.highFivesGuys();
  oui.whoAmI();
}
