// PBRT2. Chapter 13. Page 666.
vec2 uniformlySampleDisk( vec2 uniformRandomSample )
{
	float r = sqrt(uniformRandomSample.x);
	float theta = 2.0 * PI * uniformRandomSample.y;
	return vec2(r*cos(theta), r*sin(theta));
}

// Sample a hemisphere with pole at +Y axis with a distribution proportional to
// the cosine of the theta angle (that is, more likely towards the pole).
// returns vec4(dir.xyz, pdf)
// PBRT2. Chapter 13. Page 669.
vec4 cosineSampledHemisphere( vec2 uniformRandomSample )
{
	vec2 p = uniformlySampleDisk(uniformRandomSample);
	float y = sqrt(max(0.0, 1.0 - p.x*p.x - p.y*p.y));
	// cos(theta) = y
	// sampling routines are defined in terms of solid angle, not directions, so
	// we need to weight the pdf by 1/PI (PBRT2 p.670).
	float pdf = y / PI; 
	return vec4(p.s, y, p.t, pdf);
}

// Sample a hemisphere with pole at +Y axis with uniform distribution.
// returns vec4(dir.xyz, pdf)
// PBRT2. Chapter 13. Page 664.
vec4 uniformlySampledHemisphere( vec2 uniformRandomSample )
{
	float y = uniformRandomSample.x;
	float r = sqrt(max(0.0, 1.0 - y*y));
	float phi = uniformRandomSample.y * 2.0 * PI;
	float x = r * cos(phi);
	float z = r * sin(phi);
	float pdf = 1.0 / (2.0 * PI);
	return vec4(x, y, z, pdf);
}

// Used for Multiple Importance Sampling.
// PBRT2. Chapter 14. Page 693.
float powerHeuristic(float f, float g)
{
	return f*f / (f*f + g*g);
}


