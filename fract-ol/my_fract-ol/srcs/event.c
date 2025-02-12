/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:39:04 by srenaud           #+#    #+#             */
/*   Updated: 2025/02/12 10:39:04 by srenaud          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int event(int hook, void *env)
{
    if (hook == ESC_KEY || hook == 17) 
        fractol_quit((t_env *)env);
    return (0);
}