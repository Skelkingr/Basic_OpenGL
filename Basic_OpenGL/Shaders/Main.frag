#version 460 core

struct Light
{
	vec3 position;
	
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

struct Material
{
	float shininess;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

in vec3 vs_vertex;
in vec3 vs_color;
in vec2 vs_tex;

out vec4 fragColor;

uniform Light light;
uniform Material material;

uniform vec3 cameraPosition;

uniform bool isLit;
uniform bool isTextured;

uniform sampler2D textureImg;

void main()
{
	if (isLit)
	{
		/* Ambient */
		vec3 ambientColor = light.ambient * material.ambient;
		/* */

		/* Diffuse */
		vec3 normal = vec3(0.0, 1.0, 0.0);
		vec3 lightDirection = normalize(light.position - vs_vertex);
		float lightIntensity = max(dot(lightDirection, normal), 0.0);
		vec3 diffuseColor = light.diffuse * material.diffuse * lightIntensity;
		/* */

		/* Specular */
		vec3 viewDirection = normalize(cameraPosition - vs_vertex);
		vec3 reflection = reflect(-lightDirection, normal);
		float specularTerm = pow(max(dot(viewDirection, reflection), 0.0), material.shininess);
		vec3 specularColor = light.specular * material.specular * specularTerm;
		/* */

		vec3 finalColor = ambientColor + diffuseColor + specularColor;
		
		if (isTextured)
		{
			fragColor = vec4(finalColor, 1.0) * texture(textureImg, vs_tex);
		}
		else
		{
			fragColor = vec4(finalColor, 1.0);
		}
	}
	else
	{
		fragColor = vec4(vs_color, 1.0);
	}
}