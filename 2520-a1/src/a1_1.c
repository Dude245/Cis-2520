//Nathan Reymer
//0797359


#include <stdio.h>
#include <stdlib.h>
// Permustations of "Carbon"
int main(int argc, char**argv) {

	for(int c=1;c<7;c++)
		{
			for(int a=1;a<7;a++)
				{
					for(int r=1;r<7;r++)
						{
							for(int b=1;b<7;b++)
								{
									for(int o=1;o<7;o++)
										{
											for(int n=1;n<7;n++)
												{	//Make sure no duplicate letters
													if(c!=a &&c!=a &&c!=r &&c!=b &&c!=o &&c!=n &&
														a!=c &&a!=r &&a!=b &&a!=o &&a!=n &&
														r!=a &&r!=a &&r!=b &&r!=o &&r!=n &&
														b!=a &&b!=a &&b!=r &&b!=o &&b!=n &&
														o!=a &&o!=a &&o!=r &&o!=b &&o!=n &&
														n!=a &&n!=a &&n!=r &&n!=b &&n!=o)
														{
															char str[6]=">";
															//Swap numbers for letters
															for(int swap=1;swap<7;swap++)
																{
																	if(c==swap)
																		{
																			str[swap]='C';
																		}
																		if(a==swap)
																			{
																				str[swap]='A';
																			}
																			if(r==swap)
																				{
																					str[swap]='R';
																				}
																				if(b==swap)
																					{
																						str[swap]='B';
																					}
																					if(o==swap)
																						{
																							str[swap]='O';
																						}
																						if(n==swap)
																							{
																								str[swap]='N';
																							}
																						}
																						//Display permutation
																						printf("%s \n",str);
																					}

																				}
																			}
																		}
																	}
																}
															}


															return 0;
														}
