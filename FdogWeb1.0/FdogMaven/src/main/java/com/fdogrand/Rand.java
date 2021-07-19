package com.fdogrand;

public class Rand {
	private int randnum =0;
  public int ReturnRandNumer()
  {
	  randnum = (int)(Math.random()*90000+10000);
	  return randnum;
  }
  public int ReturnRandNumer_2()
  {
	  randnum = (int)(Math.random()*90000000+10000000);
	  return randnum;
  }
}
