package com.filter;

import java.io.IOException;
import java.util.Map;

import javax.servlet.FilterChain;
import javax.servlet.FilterConfig;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletRequestWrapper;
import javax.servlet.http.HttpServletResponse;

public class Filter implements javax.servlet.Filter {

    public Filter() {
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see Filter#destroy()
	 */
	public void destroy() {
		// TODO Auto-generated method stub
	}

	/**
	 * @see Filter#doFilter(ServletRequest, ServletResponse, FilterChain)
	 */
	public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws IOException, ServletException {
		HttpServletRequest hsr = (HttpServletRequest)request;
		HttpServletResponse  hst = (HttpServletResponse)response;
		hsr.setCharacterEncoding("utf-8");
		hst.setContentType("text/html;charset=utf-8");
		// pass the request along the filter chain
		if(hsr.getMethod().equalsIgnoreCase("get")){
			MyRequest myRequest = new MyRequest(hsr);
			chain.doFilter(myRequest, response);
			
		}
		else {
		chain.doFilter(request, response);
		}
	}

	/**
	 * @see Filter#init(FilterConfig)
	 */
	public void init(FilterConfig fConfig) throws ServletException {
		// TODO Auto-generated method stub
	}

}

class MyRequest extends HttpServletRequestWrapper{

	private HttpServletRequest request;
	private boolean isEncoding = false;
	
	public MyRequest(HttpServletRequest request) {
		super(request);
		this.request = request;
		// TODO Auto-generated constructor stub
	}
	@Override
	public String getParameter(String name) {
		return getParameterMap().get(name)[0];
	}
	
	@Override
	public Map<String,String[]> getParameterMap(){
		Map<String,String[]> map = request.getParameterMap();
		if(isEncoding ==true) {
			return map;
		}
		for(Map.Entry<String, String[]> entry:map.entrySet()) {
			String[] values = entry.getValue();
			for(int i = 0;i<values.length;i++) {
				try {
					values[i] = new String(values[i].getBytes("ISO-8859-1"),"utf-8");
				}catch(Exception e) {
					e.printStackTrace();
				}
			}
		}
		isEncoding = true;
		return map;
	}
}
