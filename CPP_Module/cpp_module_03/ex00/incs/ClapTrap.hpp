/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:01:16 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/25 21:15:59 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {
	private:
		std::string		_name;
		unsigned int	_hit_points;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;
	
	protected:
		// Getter
		std::string		getName(void);

		const std::string	&getName(void) const;
		unsigned int		getHitPoints(void) const;
		unsigned int		getEnergePoints(void) const;
		unsigned int		getAttackDamage(void) const;
	
		// Setter
		void			setName(const std::string &name);
		void			setHitPoints(unsigned int amount);
		void			setEnergePoints(unsigned int amount);
		void			setAttackDamage(unsigned int amount);
		
	public:
		ClapTrap(void);
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &clap_trap);
		ClapTrap	&operator=(const ClapTrap &clap_trap);
		virtual	~ClapTrap(void);
	
		// Utils
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif