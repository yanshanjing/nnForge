/*
 *  Copyright 2011-2013 Maxim Milakov
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#pragma once

#include "layer_configuration_specific.h"
#include "neuron_data_type.h"
#include "nn_types.h"

namespace nnforge
{
	class data_transformer
	{
	public:
		virtual ~data_transformer();

		virtual void transform(
			const void * data,
			void * data_transformed,
			neuron_data_type::input_type type,
			const layer_configuration_specific& original_config,
			unsigned int sample_id) = 0;

		virtual layer_configuration_specific get_transformed_configuration(const layer_configuration_specific& original_config) const;

		virtual bool is_in_place() const;

		virtual unsigned int get_sample_count() const;
		
		virtual void reset();

		virtual bool is_deterministic() const = 0;

		virtual neuron_data_type::input_type get_transformed_data_type(neuron_data_type::input_type original_data_type) const;

	protected:
		data_transformer();

	private:
		data_transformer(const data_transformer&);
		data_transformer& operator =(const data_transformer&);
	};

	typedef nnforge_shared_ptr<data_transformer> data_transformer_smart_ptr;
}
